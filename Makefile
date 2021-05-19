NAME = getnextline
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#source
SRCS =	get_next_line_utils.c get_next_line.c test.c

#objects
OBJS = $(SRCS:.c=.o)

#prefixing for space in folder while working
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

#quelques args reservEs
.PHONY	: all clean fclean re help

all	: $(NAME)

#make exec
$(NAME)	: $(OBJS_PREFIXED)
	$(CC) $(CFLAGS) -I . -o $(NAME) $<

#compiling
$(OBJS_DIR)%.o	: %.c get_next_line.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	@rm -rf $(OBJS_DIR)
	@echo "cleaning objects"

fclean	: clean
	@rm -f $(NAME)
	@echo "erasing  executable"

re	: fclean all

help	:
	@echo "all $(NAME) clean fclean re \033[0;32mtest help\033[0;39m"
