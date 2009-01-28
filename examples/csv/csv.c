#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <tokstream.h>

/* macro for string comparison */
#define is_token(tok, cmp) (strcmp(tok, cmp) == 0)

int main(int argc, char* argv[])
{
    tokstream* ts;
    const char* tok;

    int num_fields;

    if(argc != 2)
    {
        fprintf(stderr, "Usage: csv <csv_file>\n");
        return EXIT_FAILURE;
    }

    /* open tokstream */
    ts = ts_open(argv[1]);

    /* make sure ts was opened */
    if(!ts)
    {
        fprintf(stderr, "Could not open token stream\n");
        return EXIT_FAILURE;
    }

    /* set token stream separators and delimiters */
    ts_sep(ts, ",\n");
    ts_delim(ts, "\"");

    /* show the first 10 fields */
    fprintf(stdout, "First 10 fields:\n");

    /* scan file */
    num_fields = 0;
    while((tok = ts_get(ts)))
    {
        /* care for quoted words */
        if(is_token(tok, "\""))
        {
            /* get token until end of quote */
            tok = ts_seekc(ts, '\"');
            if(!tok)
            {
                fprintf(stderr, "Could not find end of quote beginning at line %d, char %d\n", ts_line(ts), ts_char(ts));
                return EXIT_FAILURE;
            }

            /* discard "end of quote" token */
            ts_skip(ts);
        }

        /* token is field */
        ++num_fields;

        /* show first fields */
        if(num_fields < 11)
            fprintf(stdout, "  %s\n", tok);
    }

    /* check for errors */
    if(!tok && !ts_eof(ts))
    {
        fprintf(stderr, "Error reading token stream\n");
        return EXIT_FAILURE;
    }

    /* show read statistics */
    fprintf(stdout, "No. of lines read: %d\n", ts_line(ts));
    fprintf(stdout, "No. of fields read: %d\n", num_fields);

    /* done */
    return EXIT_SUCCESS;
}
