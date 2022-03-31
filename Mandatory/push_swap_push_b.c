/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:00:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 22:15:57 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_mv(t_stack *stack_a)
{
	t_stack_node	*tmp_node;
	int				node_instr;
	int				i;

	node_instr = (stack_a->size / 2) + 1;
	tmp_node = stack_a->head;
	i = -1;
	while (++i < stack_a->size)
	{
		if (tmp_node->chk == 0
			&& my_abs(tmp_node->nmbr_of_instr) <= my_abs(node_instr))
			node_instr = tmp_node->nmbr_of_instr;
		tmp_node = tmp_node->next;
	}
	return (node_instr);
}

static void	ft_sub__push_b_ra(t_stack *stack_a, t_stack *stack_b,
		t_stack_node *current)
{
	while (current->nmbr_of_instr--)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_instructions_number(stack_a);
}

static void	ft_sub__push_b_rra(t_stack *stack_a, t_stack *stack_b,
		t_stack_node *current)
{
	while (current->nmbr_of_instr++)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_instructions_number(stack_a);
}

void	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*current;

	ft_instructions_number(stack_a);
	current = stack_a->head;
	while (current)
	{
		if (ft_first_mv(stack_a) >= 0
			&& current->nmbr_of_instr == ft_first_mv(stack_a))
		{
			ft_sub__push_b_ra(stack_a, stack_b, current);
			current = stack_a->head;
		}
		else if (ft_first_mv(stack_a) < 0
			&& current->nmbr_of_instr == ft_first_mv(stack_a))
		{
			ft_sub__push_b_rra(stack_a, stack_b, current);
			current = stack_a->head;
		}
		else
			current = current->next;
	}
}
