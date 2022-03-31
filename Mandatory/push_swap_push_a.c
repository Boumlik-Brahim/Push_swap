/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:25:28 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 21:39:11 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_total_moves(int nb1, int nb2)
{
	if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0))
	{
		if (my_abs(nb1) > my_abs(nb2))
			return (my_abs(nb1));
		return (my_abs(nb2));
	}
	return (my_abs(nb1) + my_abs(nb2));
}

t_stack_node	*ft_first_mv_sb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*tmp_node;
	t_stack_node	*bst_node;
	int				node_instr;
	int				i;

	ft_best_element_betwen_ht(stack_a, stack_b);
	ft_best_top_bottom_element(stack_a, stack_b);
	ft_best_max_element(stack_a, stack_b);
	i = 0;
	bst_node = stack_b->head;
	tmp_node = stack_b->head;
	node_instr = ft_get_total_moves(tmp_node->tmp[0], tmp_node->tmp[1]);
	while (i++ < stack_b->size)
	{
		if (ft_get_total_moves(tmp_node->tmp[0], tmp_node->tmp[1]) < node_instr)
		{
			node_instr = ft_get_total_moves(tmp_node->tmp[0], tmp_node->tmp[1]);
			bst_node = tmp_node;
		}
		tmp_node = tmp_node->next;
	}
	return (bst_node);
}

void	ft_sub_moves_optimisation(t_stack *stack_a, t_stack *stack_b,
		t_stack_node *best)
{
	while (best->tmp[0] > 0)
	{
		ft_ra(stack_a);
		best->tmp[0]--;
	}
	while (best->tmp[0] < 0)
	{
		ft_rra(stack_a);
		best->tmp[0]++;
	}
	while (best->tmp[1] > 0)
	{
		ft_rb(stack_b);
		best->tmp[1]--;
	}
	while (best->tmp[1] < 0)
	{
		ft_rrb(stack_b);
		best->tmp[1]++;
	}
	ft_pa(stack_a, stack_b);
}

void	ft_moves_optimisation(t_stack *stack_a, t_stack *stack_b,
		t_stack_node *best)
{
	if (best->tmp[0] >= 0 && best->tmp[1] >= 0)
	{
		while (best->tmp[0] > 0 && best->tmp[1] > 0)
		{
			ft_rr(stack_a, stack_b);
			best->tmp[0]--;
			best->tmp[1]--;
		}
	}
	else if (best->tmp[0] < 0 && best->tmp[1] < 0)
	{
		while (best->tmp[0] < 0 && best->tmp[1] < 0)
		{
			ft_rrr(stack_a, stack_b);
			best->tmp[0]++;
			best->tmp[1]++;
		}
	}
	ft_sub_moves_optimisation(stack_a, stack_b, best);
}

void	ft_final_sort(t_stack *stack_a)
{
	t_stack_node	*current;
	int				min_data;

	ft_instructions_number(stack_a);
	min_data = ft_min_data(stack_a);
	current = stack_a->head;
	while (current)
	{
		if (current->index <= (stack_a->size / 2)
			&& (current->data == min_data))
		{
			while (current->nmbr_of_instr--)
				ft_ra(stack_a);
			ft_instructions_number(stack_a);
		}
		else if (current->index > (stack_a->size / 2)
			&& (current->data == min_data))
		{
			while (current->nmbr_of_instr++)
				ft_rra(stack_a);
			ft_instructions_number(stack_a);
		}
		current = current->next;
	}
}
