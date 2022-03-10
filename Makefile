CC = gcc
CFLAGS = -Wall -Werror -Wextra

PUSH_SWAP = push_swap


NAME = $(PUSH_SWAP)
LIBFT = Libft/libft.a

all: $(NAME)

$(PUSH_SWAP): SRC/push_swap.c SRC/push_swap_utils.c SRC/push_swap_instructions.c $(LIBFT)
	$(CC) $(CFLAGS) SRC/push_swap.c SRC/push_swap_utils.c SRC/push_swap_instructions.c $(LIBFT) -o $(PUSH_SWAP)

$(LIBFT): $(shell find Libft/ -name "*.c" -type f)
	$(MAKE) -C Libft 

clean:
	$(MAKE) -C Libft clean

fclean: clean
	$(MAKE) -C Libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re