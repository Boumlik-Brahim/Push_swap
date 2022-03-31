/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ra_rb_rr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:50:36 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 20:34:30 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack *ra)
{
	if (ra->size <= 1)
		return ;
	ra->tail->next = ra->head;
	ra->head->prev = ra->tail;
	ra->head = ra->head->next;
	ra->tail = ra->tail->next;
	ra->head->prev = NULL;
	ra->tail->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack *rb)
{
	if (rb->size <= 1)
		return ;
	rb->tail->next = rb->head;
	rb->head->prev = rb->tail;
	rb->head = rb->head->next;
	rb->tail = rb->tail->next;
	rb->head->prev = NULL;
	rb->tail->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack *ra, t_stack *rb)
{
	if (ra->size <= 1 || rb->size <= 1)
		return ;
	ra->tail->next = ra->head;
	ra->head->prev = ra->tail;
	ra->head = ra->head->next;
	ra->tail = ra->tail->next;
	ra->head->prev = NULL;
	ra->tail->next = NULL;
	rb->tail->next = rb->head;
	rb->head->prev = rb->tail;
	rb->head = rb->head->next;
	rb->tail = rb->tail->next;
	rb->head->prev = NULL;
	rb->tail->next = NULL;
	ft_putstr_fd("rr\n", 1);
}
