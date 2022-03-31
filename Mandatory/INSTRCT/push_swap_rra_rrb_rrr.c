/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rra_rrb_rrr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:50:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 20:39:05 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack *rra)
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
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack *rrb)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (rrb->size <= 1)
		return ;
	tmp = rrb->head;
	tmp2 = rrb->tail;
	rrb->tail = rrb->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rrb->head = tmp2;
	rrb->tail->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *rra, t_stack *rrb)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (rra->size <= 1 || rrb->size <= 1)
		return ;
	tmp = rra->head;
	tmp2 = rra->tail;
	rra->tail = rra->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rra->head = tmp2;
	rra->tail->next = NULL;
	tmp = rrb->head;
	tmp2 = rrb->tail;
	rrb->tail = rrb->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rrb->head = tmp2;
	rrb->tail->next = NULL;
	ft_putstr_fd("rrr\n", 1);
}
