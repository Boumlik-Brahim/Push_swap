/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:52:48 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:49:10 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra_b(t_stack_b *rab)
{
	if (rab->size <= 1)
		return ;
	rab->tail->next = rab->head;
	rab->head->prev = rab->tail;
	rab->head = rab->head->next;
	rab->tail = rab->tail->next;
	rab->head->prev = NULL;
	rab->tail->next = NULL;
}

void	ft_rb_b(t_stack_b *rbb)
{
	if (rbb->size <= 1)
		return ;
	rbb->tail->next = rbb->head;
	rbb->head->prev = rbb->tail;
	rbb->head = rbb->head->next;
	rbb->tail = rbb->tail->next;
	rbb->head->prev = NULL;
	rbb->tail->next = NULL;
}

void	ft_rr_b(t_stack_b *rab, t_stack_b *rbb)
{
	if (rab->size <= 1 || rbb->size <= 1)
		return ;
	rab->tail->next = rab->head;
	rab->head->prev = rab->tail;
	rab->head = rab->head->next;
	rab->tail = rab->tail->next;
	rab->head->prev = NULL;
	rab->tail->next = NULL;
	rbb->tail->next = rbb->head;
	rbb->head->prev = rbb->tail;
	rbb->head = rbb->head->next;
	rbb->tail = rbb->tail->next;
	rbb->head->prev = NULL;
	rbb->tail->next = NULL;
}
