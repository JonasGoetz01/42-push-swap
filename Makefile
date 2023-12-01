NAME	:= push_swap

CFLAGS	:= -Wextra -Wall -Werror

CC		:= cc

HEADERS	:= -I ./includes/*.h

LIB := ./libft/libft.a

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)main.c \
			$(SRCDIR)lst.c \
			$(SRCDIR)p_functions.c \
			$(SRCDIR)r_functions.c \
			$(SRCDIR)rr_functions.c \
			$(SRCDIR)s_functions.c

OBJS	:= ${SRCS:.c=.o}

lib:
	make -C ./libft

$(NAME): $(OBJS) lib
	$(CC) $(OBJS) $(LIB) $(HEADERS) -o $(NAME)

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
