# Line by line file reader
Fnction made for 42 in C reading files line by line.

## function

 - int get_next_line(int fd, char **line);
 ### params
 - fd : file descriptor
 - line : pointeur sur la string lu
 ### return
 - 1 : Une ligne a été lue
 - 0 : La fin de fichier a été atteinte
 - -1 : Une erreur est survenue

## compiling
 gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

## tested
 test with Tripouille/gnlTester
