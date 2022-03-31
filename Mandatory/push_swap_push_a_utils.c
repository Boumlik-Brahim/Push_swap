/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_a_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:07:05 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 22:43:38 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_best_element_betwen_ht(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node		*current_b;
	t_stack_node		*head_a;
	t_stack_node		*tail_a;

	ft_instructions_number(stack_a);
	ft_instructions_number(stack_b);
	head_a = stack_a->head;
	tail_a = stack_a->tail;
	current_b = stack_b->head;
	while (current_b)
	{
		if (head_a->data > current_b->data && tail_a->data < current_b->data)
		{
			current_b->tmp[0] = head_a->nmbr_of_instr;
			current_b->tmp[1] = current_b->nmbr_of_instr;
		}
		current_b = current_b->next;
	}
}

void	ft_best_max_element(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*current_b;

	ft_instructions_number(stack_a);
	ft_instructions_number(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		if (current_b->data > ft_max_data(stack_a))
		{
			current_b->tmp[0] = ft_max_data_nbr_istr(stack_a);
			current_b->tmp[1] = current_b->nmbr_of_instr;
		}
		current_b = current_b->next;
	}
}

static void	ft_sub_best_top_bottom_element(t_stack_node *current_b,
		t_stack_node *current_head_a, t_stack_node *current_next_a)
{
	if (current_b->data > current_head_a->data
		&& current_b->data < current_next_a->data)
	{
		current_b->tmp[0] = current_next_a->nmbr_of_instr;
		current_b->tmp[1] = current_b->nmbr_of_instr;
	}
}

void	ft_best_top_bottom_element(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node		*current_b;
	t_stack_node		*current_head_a;
	t_stack_node		*current_next_a;

	ft_instructions_number(stack_a);
	ft_instructions_number(stack_b);
	current_head_a = stack_a->head;
	current_b = stack_b->head;
	while (current_b)
	{
		current_head_a = stack_a->head;
		while (current_head_a)
		{
			current_next_a = current_head_a->next;
			while (current_next_a)
			{
				ft_sub_best_top_bottom_element(current_b,
					current_head_a, current_next_a);
				current_next_a = current_next_a->next;
				break ;
			}
			current_head_a = current_head_a->next;
		}
		current_b = current_b->next;
	}
}

void	ft_sort_three(t_stack *stack_a)
{
	if (stack_a->head->data == ft_min_data(stack_a)
		&& stack_a->head->next->data > stack_a->tail->data)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (stack_a->head->next->data == ft_min_data(stack_a))
	{
		if (stack_a->head->data > stack_a->tail->data)
			ft_ra(stack_a);
		else
			ft_sa(stack_a);
	}
	else if (stack_a->tail->data == ft_min_data(stack_a))
	{
		if (stack_a->head->data > stack_a->head->next->data)
			ft_sa(stack_a);
		ft_rra(stack_a);
	}
}
