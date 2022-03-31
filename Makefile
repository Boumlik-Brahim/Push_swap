CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT = Libft/libft.a

SRC = Mandatory/INSTRCT/push_swap_sa_sb_ss.c Mandatory/INSTRCT/push_swap_rra_rrb_rrr.c Mandatory/INSTRCT/push_swap_ra_rb_rr.c Mandatory/INSTRCT/push_swap_pa_pb.c \
		Mandatory/push_swap.c Mandatory/push_swap_utils.c Mandatory/push_swap_lis.c Mandatory/push_swap_push_b.c Mandatory/push_swap_push_a.c \
		Mandatory/push_swap_push_a_utils.c Mandatory/push_swap_min.c Mandatory/push_swap_errors.c Mandatory/push_swap_free_stacks.c \
		Mandatory/push_swap_max_min.c

SRC_BONUS = Bonus/checker.c Bonus/checker_utils.c Bonus/checker_pa_pb.c Bonus/checker_ra_rb_rr.c Bonus/checker_rra_rrb_rrr.c Bonus/checker_sa_sb_ss.c\
		Bonus/checker_errors.c Bonus/get_next_line.c

all: $(NAME)
bonus: checker

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

checker: $(SRC_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o checker

$(LIBFT): $(shell find Libft/ -name "*.c" -type f)
	$(MAKE) -C Libft 

clean:
	$(MAKE) -C Libft clean

fclean: clean
	$(MAKE) -C Libft fclean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re bonus