# gnl
get_next_line

This is a simple C program that reads a line from a file descriptor.
It compiles on linux and Mac.
It is a 42 school project. It is meant to teach us about static variables.
The bonus part allows you to read from multiple file descriptors in any order without any mixup.

Compiling the basic version:

`gcc get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=1024`

Compiling the bonus version:

`gcc get_next_line_bonus.c get_next_line_utils_bonus.c main.c -D BUFFER_SIZE=1024`

Of course you can set the BUFFER_SIZE to any positive value you want.
