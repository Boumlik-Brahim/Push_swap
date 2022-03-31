/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_max_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:49:50 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 21:19:12 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

int	ft_min_data(t_stack *stack_a)
{
	t_stack_node	*tmp;
	t_stack_node	*min;

	tmp = stack_a->head;
	min = tmp;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	min->subsequence = -1;
	return (min->data);
}

int	ft_max_data(t_stack *stack_a)
{
	t_stack_node	*tmp;
	int				max_data;
	int				i;

	i = -1;
	tmp = stack_a->head;
	max_data = tmp->data;
	while (++i < stack_a->size)
	{
		if (tmp->data > max_data)
			max_data = tmp->data;
		tmp = tmp->next;
	}
	return (max_data);
}

int	ft_max_data_nbr_istr(t_stack *stack_a)
{
	t_stack_node	*tmp;
	int				max_data;
	int				max_data_instruction;
	int				i;

	i = -1;
	max_data = ft_max_data(stack_a);
	tmp = stack_a->head;
	while (++i < stack_a->size)
	{
		if (tmp->data == max_data)
			max_data_instruction = tmp->nmbr_of_instr + 1;
		tmp = tmp->next;
	}
	return (max_data_instruction);
}
