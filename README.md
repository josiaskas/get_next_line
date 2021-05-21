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
Le code n'a pas de leaks (connu pour le moment), mais il doit etre ameliorer surout vu le nombre de fonction. J'ai essayer d'utilser au maximum les function de la libft(ecole 42). 
Vous pouvez utiliser les fonctions de la librairie C. 
## compiling
 test compiling with :
 gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main_test.c
 ```sh
  gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main_test.c
 ```

## tested
- Tripouille/gnlTester (https://github.com/Tripouille/gnlTester)
- memory leaks test with (https://github.com/charMstr/GNL_lover)
