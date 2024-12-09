NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm -f

SRC = push_swap.c parser.c t_struct.c atoi_pushswap.c utils.c \
mov_swap_push.c mov_rotate.c mov_reverserotate.c sorting.c \
set_stacks.c \

INCLUDE = push_swap.h

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re