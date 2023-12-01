NAME	:= push_swap

CFLAGS	:= -Wextra -Wall -Werror -g

CC		:= gcc

HEADERS	:= -I ./includes/*.h

LIB := ./libft/libft.a

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)main.c \
			$(SRCDIR)lst.c \
			$(SRCDIR)lst2.c \
			$(SRCDIR)p_functions.c \
			$(SRCDIR)r_functions.c \
			$(SRCDIR)rr_functions.c \
			$(SRCDIR)s_functions.c \
			$(SRCDIR)quick_sort.c

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
