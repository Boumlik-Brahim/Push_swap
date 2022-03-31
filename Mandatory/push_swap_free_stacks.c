/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:53:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 21:04:44 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack_a(t_stack *stack_a)
{
	t_stack_node	*root;
	t_stack_node	*ptr;

	root = NULL;
	ptr = stack_a->head;
	if (!stack_a->head)
		stack_a->head = NULL;
	while (ptr != NULL)
	{
		root = ptr;
		ptr = ptr->next;
		free(root);
	}
	stack_a->head = NULL;
}

void	ft_free_stack_b(t_stack *stack_b)
{
	t_stack_node	*root;
	t_stack_node	*ptr;

	root = NULL;
	ptr = stack_b->head;
	if (!stack_b->head)
		stack_b->head = NULL;
	while (ptr != NULL)
	{
		root = ptr;
		ptr = ptr->next;
		free(root);
	}
	stack_b->head = NULL;
}

void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stack_a(stack_a);
	ft_free_stack_b(stack_b);
}
