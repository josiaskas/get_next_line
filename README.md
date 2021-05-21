# Line by line file reader
Function made for 42 in C reading files line by line.

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
 test compiling with :
 gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main_test.c
 ```sh
  gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main_test.c
 ```

## tested
- 42 test
 test with Tripouille/gnlTester
- memory leaks and 42 test also
 test with charMstr/GNL_lover
