NAME = push_swap

LIB = ./lib/libftprintf.a
INC = inc/
SRC_DIR = src/
OBJ_DIR = obj/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I
RM = rm -f

SRCS = $(SRC_DIR)push.c \
		$(SRC_DIR)rev_rotate.c \
		$(SRC_DIR)rotate.c \
		$(SRC_DIR)sort_stacks.c \
		$(SRC_DIR)sort_stacks2.c \
		$(SRC_DIR)sort_three.c \
		$(SRC_DIR)swap.c \
		$(SRC_DIR)handle_errors.c \
		$(SRC_DIR)init_a_to_b.c \
		$(SRC_DIR)init_b_to_a.c \
		$(SRC_DIR)push_swap.c \
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