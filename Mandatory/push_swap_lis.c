/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:31:33 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 21:13:27 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sub_index_lenght(int *nmber_befor, int *index_befor,
		t_stack_node *current, t_stack_node *nxt)
{
	if (current->lenth + 1 > nxt->lenth)
	{
		nxt->lenth = current->lenth + 1;
		nxt->subsequence = current->index;
		*nmber_befor = current->data;
		*index_befor = current->index;
	}
	else if (current->lenth + 1 == nxt->lenth)
	{
		if (current->data < *nmber_befor)
			nxt->subsequence = current->index;
		else
			nxt->subsequence = *index_befor;
	}
}

void	ft_index_lenght(t_stack *stack_a)
{
	t_stack_node	*current;
	t_stack_node	*nxt;
	int				nember_befor;
	int				index_befor;

	current = stack_a->head;
	nxt = current->next;
	while (nxt)
	{
		current = stack_a->head;
		while (current != nxt && current)
		{
			if (current->data < nxt->data)
				ft_sub_index_lenght(&nember_befor, &index_befor, current, nxt);
			current = current->next;
		}
		nxt = nxt->next;
	}
}

void	ft_lis(t_stack *stack_a)
{
	t_stack_node	*current;
	t_stack_node	*nxt;
	int				i;
	int				length;

	current = stack_a->head;
	nxt = stack_a->head->next;
	while (nxt)
	{
		if (nxt->lenth > current->lenth)
			current = nxt;
		nxt = nxt->next;
	}
	length = current->lenth;
	while (length--)
	{
		current->chk = 1;
		i = 0;
		nxt = stack_a->head;
		while (i++ < current->subsequence)
			nxt = nxt->next;
		current = nxt;
	}
}
