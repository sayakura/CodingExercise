
    • When reading from a regular file, if the end of file is reached before the requested number of bytes has been read.
        For example, if 30 bytes remain until the end of file and we try to read 100 bytes, read returns 30. The next time we
        call read, it will return 0 (end of file).

    • When reading from a terminal device. Normally, up to one line is read at a time.

    • When reading from a network. Buffering within the network may cause less than the requested amount to be returned.

    • When reading from a pipe or FIFO. If the pipe contains fewer bytes than requested, read will return only what is available.

    • The read operation starts at the file’s current offset. Before a successful return, the offset is incremented by the number of bytes actually read.

    Most file systems support some kind of read-ahead to improve performance.
    When sequential reads are detected, the system tries to read in more data than an application requests, assuming that the application will read it shortly. 
    
    Beware when trying to measure the performance of programs that read and write files. The operating system will try to cache the file incore,
    so if you measure the performance of the program repeatedly, the successive timings will likely be better than the first.
    This improvement occurs because the first run causes the file to be entered into the system’s cache,
    and successive runs access the file from the system’s cache instead of from the disk. (The term incore means in main memory). 
