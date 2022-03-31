/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sa_sb_ss.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:46:29 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:50:33 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa_b(t_stack_b *sab)
{
	t_stack_node_b	*tmp;
	t_stack_node_b	*tmp2;

	if (sab->size > 2)
	{
		tmp = sab->head->next;
		tmp2 = tmp->next;
		tmp->next = sab->head;
		sab->head->prev = tmp;
		sab->head->next = tmp2;
		tmp2->prev = sab->head;
		sab->head = tmp;
		sab->head->prev = NULL;
	}
	else if (sab->size == 2)
	{
		sab->tail = sab->head;
		sab->head = sab->head->next;
		sab->head->next = sab->tail;
		sab->tail->prev = sab->head;
		sab->tail->next = NULL;
		sab->head->prev = NULL;
	}
}

void	ft_sb_b(t_stack_b *sbb)
{
	t_stack_node_b	*tmp;
	t_stack_node_b	*tmp2;

	if (sbb->size > 2)
	{
		tmp = sbb->head->next;
		tmp2 = tmp->next;
		tmp->next = sbb->head;
		sbb->head->prev = tmp;
		sbb->head->next = tmp2;
		tmp2->prev = sbb->head;
		sbb->head = tmp;
		sbb->head->prev = NULL;
	}
	else if (sbb->size == 2)
	{
		sbb->tail = sbb->head;
		sbb->head = sbb->head->next;
		sbb->head->next = sbb->tail;
		sbb->tail->prev = sbb->head;
		sbb->tail->next = NULL;
		sbb->head->prev = NULL;
	}
}

void	ft_ss_b(t_stack_b *sab, t_stack_b *sbb)
{
	ft_sa_b(sab);
	ft_sb_b(sbb);
}
