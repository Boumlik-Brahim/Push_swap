/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:41:55 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 23:08:49 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../Libft/libft.h"

# define NC "\033[31;0m"
# define RED "\033[31;0m\033[0;31;1m"

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	int					data;
	int					index;
	int					lenth;
	int					subsequence;
	int					chk;
	int					nmbr_of_instr;
	int					tmp[2];
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head;
	t_stack_node	*tail;
	int				size;
}	t_stack;

void			ft_sa(t_stack *sa);
void			ft_sb(t_stack *sb);
void			ft_ss(t_stack *sa, t_stack *sb);
void			ft_ra(t_stack *ra);
void			ft_rb(t_stack *rb);
void			ft_rr(t_stack *ra, t_stack *rb);
void			ft_rra(t_stack *rra);
void			ft_rrb(t_stack *rrb);
void			ft_rrr(t_stack *rra, t_stack *rrb);
void			ft_pa(t_stack *pa, t_stack *pb);
void			ft_pb(t_stack *pa, t_stack *pb);
void			ft_init_node(t_stack_node *node, int data);
char			**ft_join_args(int i, int ac, char **av);
void			ft_push(t_stack *stack, int data);
void			ft_index(t_stack *stack_a);
void			ft_instructions_number(t_stack *stack_a);
int				my_abs(int nbr);
int				ft_min_data(t_stack *stack_a);
int				ft_max_data(t_stack *stack_a);
int				ft_max_data_nbr_istr(t_stack *stack_a);
int				ft_put_min_in_top(t_stack *stack_a);
void			ft_put_min_in_old_place(t_stack *stack_a, int moves);
void			ft_index_lenght(t_stack *stack_a);
void			ft_lis(t_stack *stack_a);
int				ft_first_mv(t_stack *stack_a);
void			ft_push_b(t_stack *stack_a, t_stack *stack_b);
void			ft_best_element_betwen_ht(t_stack *stack_a, t_stack *stack_b);
void			ft_best_max_element(t_stack *stack_a, t_stack *stack_b);
void			ft_best_top_bottom_element(t_stack *stack_a, t_stack *stack_b);
void			ft_sort_three(t_stack *stack_a);
int				ft_get_total_moves(int nb1, int nb2);
t_stack_node	*ft_first_mv_sb(t_stack *stack_a, t_stack *stack_b);
void			ft_sub_moves_optimisation2(t_stack *stack_a,
					t_stack *stack_b, t_stack_node *best);
void			ft_moves_optimisation(t_stack *stack_a, t_stack *stack_b,
					t_stack_node *best);
void			ft_final_sort(t_stack *stack_a);
void			ft_handle_error(char *str);
void			ft_check_dup(t_stack *stack_a);
void			ft_empty_arg(int ac, char **av);
void			ft_check_integers(char **str);
void			ft_is_sorted(t_stack *stack_a);
void			ft_free_stack_a(t_stack *stack_a);
void			ft_free_stack_b(t_stack *stack_b);
void			ft_free_stacks(t_stack *stack_a, t_stack *stack_b);
void			ft_sort(t_stack *stack_a, t_stack *stack_b, int moves);

#endif
