NAME = getnextline
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

#source
SRCS =	test.c get_next_line.c get_next_line_utils.c

#objects
OBJS = $(SRCS:.c=.o)

#BUFFER SIZE
BUFFER?=42
#quelques args reservEs
.PHONY	: all clean fclean re help

all	: $(NAME)

#make exec
$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
#compiling
%.o : %.c get_next_line.h
	@$(CC) $(CFALGS) -D BUFFER_SIZE=$(BUFFER) -o $@ -c $<

clean	:
	@rm -rf *.o
	@echo "cleaning objects"

fclean	: clean
	@rm -f $(NAME)
	@echo "erasing  executable"

re	: fclean all

help	:
	@echo "all $(NAME) clean fclean re \033[0;32mtest help\033[0;39m"
