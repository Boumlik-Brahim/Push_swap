/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:59:13 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:55:18 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../Libft/libft.h"

# define NC "\033[31;0m"
# define RED "\033[31;0m\033[0;31;1m"

typedef struct s_stack_node_b
{
	struct s_stack_node_b	*prev;
	int						data;
	int						index;
	int						lenth;
	int						subsequence;
	int						chk;
	int						nmbr_of_instr;
	int						tmp[2];
	struct s_stack_node_b	*next;
}t_stack_node_b;

typedef struct s_stack_b
{
	t_stack_node_b	*head;
	t_stack_node_b	*tail;
	int				size;
}t_stack_b;

void	ft_pa_b(t_stack_b *pab, t_stack_b *pbb);
void	ft_pb_b(t_stack_b *pab, t_stack_b *pbb);
void	ft_ra_b(t_stack_b *rab);
void	ft_rb_b(t_stack_b *rbb);
void	ft_rr_b(t_stack_b *rab, t_stack_b *rbb);
void	ft_rra_b(t_stack_b *rrab);
void	ft_rrb_b(t_stack_b *rrbb);
void	ft_rrr_b(t_stack_b *rrab, t_stack_b *rrbb);
void	ft_sa_b(t_stack_b *sab);
void	ft_sb_b(t_stack_b *sbb);
void	ft_ss_b(t_stack_b *sab, t_stack_b *sbb);
void	ft_handle_error(char *str);
void	ft_empty_arg(int ac, char **av);
void	ft_check_integers(char **str);
void	ft_check_dup_b(t_stack_b *stack_a);
int		ft_check_is_sorted(t_stack_b *stack_a);
void	free_data(char **ptr);
void	ft_init_node_b(t_stack_node_b *node, int data);
char	**ft_join_args(int i, int ac, char **av);
void	ft_push_b(t_stack_b *stack, int data);
void	ft_free_stack_a_b(t_stack_b *stack_a);
void	ft_free_stack_b_b(t_stack_b *stack_b);
char	*get_next_line(int fd);
void	ft_check_inst(char *instruction, t_stack_b *stack_a,
			t_stack_b *stack_b);
void	ft_get_inst(t_stack_b *stack_a, t_stack_b *stack_b);

#endif
