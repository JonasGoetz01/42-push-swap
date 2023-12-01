NAME	:= pushswap

CFLAGS	:= -Wextra -Wall -Werror

CC		:= cc

HEADERS	:= -I ./includes

LIB := ./libft/libft.a

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)main.c

OBJS	:= ${SRCS:.c=.o}

lib:
	make -C ./libft

$(NAME): $(OBJS) lib
	@$(CC) $(OBJS) $(LIB) $(HEADERS) -o $(NAME)

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
