/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:40:41 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 20:55:48 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sub_sort(t_stack *stack_a, t_stack *stack_b, t_stack_node *bstmv)
{
	if (stack_b->size != 0)
	{
		while (stack_b->size)
		{
			bstmv = ft_first_mv_sb(stack_a, stack_b);
			ft_moves_optimisation(stack_a, stack_b, bstmv);
		}
		ft_final_sort(stack_a);
		ft_free_stacks(stack_a, stack_b);
	}
	else
	{
		ft_final_sort(stack_a);
		ft_free_stack_a(stack_a);
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int moves)
{
	t_stack_node	*bstmv;

	bstmv = NULL;
	ft_check_dup(stack_a);
	ft_is_sorted(stack_a);
	if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else
	{
		moves = ft_put_min_in_top(stack_a);
		ft_index_lenght(stack_a);
		ft_lis(stack_a);
		ft_put_min_in_old_place(stack_a, moves);
		ft_first_mv(stack_a);
		ft_push_b(stack_a, stack_b);
		ft_sub_sort(stack_a, stack_b, bstmv);
	}
}

int	main(int ac, char **av)
{
	t_stack			stack_a;
	t_stack			stack_b;
	char			**data;
	int				i;
	int				a;

	i = 0;
	if (ac == 1)
		return (0);
	data = ft_join_args(i, ac, av);
	i = 0;
	while (data[i])
		i++;
	while (i > 0)
	{
		a = ft_atoi(data[--i]);
		ft_push(&stack_a, a);
	}
	a = 0;
	ft_sort(&stack_a, &stack_b, a);
	for (int i = 0 ; data[i]; i++)
		free(data[i]);
	free(data);
	return (0);
}
