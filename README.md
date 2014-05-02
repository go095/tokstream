tokstream
=========

The *tokstream* library allows you to read text files and split them up into individual tokens. It is, in a sense, a glorified version of strtok with file reading and a few tricks to make the process as efficient as possible.


Documentation
-------------

There is a Doxygen-generated API documentation available [here](http://ntessore.github.io/tokstream).


Features
--------

-   clean and minimal interface
-   simple to use
-   wraps file I/O
-   high performance
-   no reading overhead, input buffering


File reading
------------

Getting tokens from files is easy enough:

    tokstream* ts = ts_open('myfile');
    
    while(!ts_eof(ts))
    {
        const char* tok = ts_get(ts);
        ...
    }
    
    ts_close(ts);

Additionally, the library contains a state stack onto which you can push the current input state. It is then possible to further process the file and jump back to this state, with minimal reading overhead. This can be very handy in certain situations, ie. if one needs to do counting of input elements.


Structure
---------

The library itself consists of nothing more than a pair of header and implementation files, allowing for direct inclusion into projects. (Of course, it can be built as an external library as well.)

CMake files for building tokstream and examples are included.

