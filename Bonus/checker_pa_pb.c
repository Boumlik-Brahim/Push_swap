/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pa_pb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:45:37 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:46:58 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_sub_pa_b(t_stack_b *pab, t_stack_b *pbb)
{
	pab->size++;
	pbb->size--;
}

void	ft_pa_b(t_stack_b *pab, t_stack_b *pbb)
{
	t_stack_node_b	*tmp;
	t_stack_node_b	*tmp2;

	if (pbb->size >= 1 && pab->size != 0)
	{
		tmp = pbb->head;
		tmp2 = pab->head;
		pbb->head = pbb->head->next;
		tmp->next = tmp2;
		tmp2->prev = tmp;
		pab->head = tmp;
		pab->head->prev = NULL;
		ft_sub_pa_b(pab, pbb);
	}
	else if (pab->size == 0)
	{
		tmp = pbb->head;
		pab->head = pbb->head;
		pbb->head = tmp->next;
		pab->head->data = tmp->data;
		pab->head->next = NULL;
		pab->tail = pab->head;
		ft_sub_pa_b(pab, pbb);
	}
}

static void	ft_sub_pb_b(t_stack_b *pab, t_stack_b *pbb,
		t_stack_node_b *tmp, t_stack_node_b	*tmp2)
{
	if (pab->size >= 1 && pbb->size != 0)
	{
		tmp = pab->head;
		tmp2 = pbb->head;
		pab->head = pab->head->next;
		tmp->next = tmp2;
		tmp2->prev = tmp;
		pbb->head = tmp;
		pab->head->prev = NULL;
		pbb->size++;
		pab->size--;
	}
	else if (pbb->size == 0)
	{
		tmp = pab->head;
		pbb->head = pab->head;
		pab->head = tmp->next;
		pbb->head->data = tmp->data;
		pbb->head->next = NULL;
		pbb->tail = pbb->head;
		pbb->size++;
		pab->size--;
	}
}

void	ft_pb_b(t_stack_b *pab, t_stack_b *pbb)
{
	t_stack_node_b	*tmp;
	t_stack_node_b	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (pab->head == NULL || pab->size == 1)
		return ;
	ft_sub_pb_b(pab, pbb, tmp, tmp2);
}
