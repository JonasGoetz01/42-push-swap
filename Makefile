NAME = push_swap

LIB = ./lib/libftprintf.a
INC = inc/
SRC_DIR = src/
OBJ_DIR = obj/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I
RM = rm -f

SRCS = $(SRC_DIR)p_functions.c \
		$(SRC_DIR)rr_functions.c \
		$(SRC_DIR)r_functions.c \
		$(SRC_DIR)s_functions.c \
		$(SRC_DIR)turk_sort.c \
		$(SRC_DIR)turk_sort2.c \
		$(SRC_DIR)sort_three.c \
		$(SRC_DIR)errors.c \
		$(SRC_DIR)stacka.c \
		$(SRC_DIR)stackb.c \
		$(SRC_DIR)stack_general.c \
		$(SRC_DIR)main.c \
		$(SRC_DIR)stack_init.c \
		$(SRC_DIR)lst.c \
		$(SRC_DIR)lst2.c \
		$(SRC_DIR)stack_utils.c

OBJS := ${SRCS:.c=.o}

start:
	@make all

$(LIB):
	@make -C ./lib

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJS)
	@make clean -C ./lib

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB)

re: fclean all

.PHONY: start all clean fclean re