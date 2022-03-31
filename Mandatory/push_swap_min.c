/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:01:42 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 21:27:32 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r_min(t_stack *ra)
{
	if (ra->size <= 1)
		return ;
	ra->tail->next = ra->head;
	ra->head->prev = ra->tail;
	ra->head = ra->head->next;
	ra->tail = ra->tail->next;
	ra->head->prev = NULL;
	ra->tail->next = NULL;
}

static void	ft_rr_min(t_stack *rra)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (rra->size <= 1)
		return ;
	tmp = rra->head;
	tmp2 = rra->tail;
	rra->tail = rra->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rra->head = tmp2;
	rra->tail->next = NULL;
}

static void	ft_sub_put_min_in_top(t_stack *stack_a, t_stack_node *current,
		int *min_data, int *moves)
{
	if (current->index <= (stack_a->size / 2) && (current->data == *min_data))
	{
		*moves = current->nmbr_of_instr;
		while (current->nmbr_of_instr--)
			ft_r_min(stack_a);
		ft_instructions_number(stack_a);
	}
	else if (current->index > (stack_a->size / 2)
		&& (current->data == *min_data))
	{
		*moves = current->nmbr_of_instr;
		while (current->nmbr_of_instr++)
			ft_rr_min(stack_a);
		ft_instructions_number(stack_a);
	}
}

int	ft_put_min_in_top(t_stack *stack_a)
{
	t_stack_node	*current;
	int				min_data;
	int				moves;

	ft_instructions_number(stack_a);
	min_data = ft_min_data(stack_a);
	current = stack_a->head;
	moves = 0;
	while (current)
	{
		ft_sub_put_min_in_top(stack_a, current, &min_data, &moves);
		current = current->next;
	}
	return (moves);
}

void	ft_put_min_in_old_place(t_stack *stack_a, int moves)
{
	t_stack_node	*current;
	int				min_data;

	ft_instructions_number(stack_a);
	min_data = ft_min_data(stack_a);
	current = stack_a->head;
	while (current)
	{
		if (moves >= 0 && (current->data == min_data))
		{
			while (moves--)
				ft_rr_min(stack_a);
			ft_instructions_number(stack_a);
		}
		else if (moves < 0 && (current->data == min_data))
		{
			while (moves++)
				ft_r_min(stack_a);
			ft_instructions_number(stack_a);
		}
		current = current->next;
	}
}
