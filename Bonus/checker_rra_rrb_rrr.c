/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rra_rrb_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:46:09 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:49:38 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra_b(t_stack_b *rrab)
{
	t_stack_node_b	*tmp;
	t_stack_node_b	*tmp2;

	if (rrab->size <= 1)
		return ;
	tmp = rrab->head;
	tmp2 = rrab->tail;
	rrab->tail = rrab->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rrab->head = tmp2;
	rrab->tail->next = NULL;
}

void	ft_rrb_b(t_stack_b *rrb)
{
	t_stack_node_b	*tmp;
	t_stack_node_b	*tmp2;

	if (rrb->size <= 1)
		return ;
	tmp = rrb->head;
	tmp2 = rrb->tail;
	rrb->tail = rrb->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rrb->head = tmp2;
	rrb->tail->next = NULL;
}

void	ft_rrr_b(t_stack_b *rrab, t_stack_b *rrbb)
{
	t_stack_node_b	*tmp;
	t_stack_node_b	*tmp2;

	if (rrab->size <= 1 || rrbb->size <= 1)
		return ;
	tmp = rrab->head;
	tmp2 = rrab->tail;
	rrab->tail = rrab->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rrab->head = tmp2;
	rrab->tail->next = NULL;
	tmp = rrbb->head;
	tmp2 = rrbb->tail;
	rrbb->tail = rrbb->tail->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	rrbb->head = tmp2;
	rrbb->tail->next = NULL;
}
