/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pa_pb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:51:19 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 20:31:00 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_sub_pa(t_stack *pa, t_stack *pb)
{
	pa->size++;
	pb->size--;
}

void	ft_pa(t_stack *pa, t_stack *pb)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (pb->size >= 1 && pa->size != 0)
	{
		tmp = pb->head;
		tmp2 = pa->head;
		pb->head = pb->head->next;
		tmp->next = tmp2;
		tmp2->prev = tmp;
		pa->head = tmp;
		pa->head->prev = NULL;
		ft_sub_pa(pa, pb);
	}
	else if (pa->size == 0)
	{
		tmp = pb->head;
		pa->head = pb->head;
		pb->head = tmp->next;
		pa->head->data = tmp->data;
		pa->head->next = NULL;
		pa->tail = pa->head;
		ft_sub_pa(pa, pb);
	}
	ft_putstr_fd("pa\n", 1);
}

static void	ft_sub_pb(t_stack *pa, t_stack *pb)
{
	pb->size++;
	pa->size--;
}

void	ft_pb(t_stack *pa, t_stack *pb)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (pa->size >= 1 && pb->size != 0)
	{
		tmp = pa->head;
		tmp2 = pb->head;
		pa->head = pa->head->next;
		tmp->next = tmp2;
		tmp2->prev = tmp;
		pb->head = tmp;
		pa->head->prev = NULL;
		ft_sub_pb(pa, pb);
	}
	else if (pb->size == 0)
	{
		tmp = pa->head;
		pb->head = pa->head;
		pa->head = tmp->next;
		pb->head->data = tmp->data;
		pb->head->next = NULL;
		pb->tail = pb->head;
		ft_sub_pb(pa, pb);
	}
	ft_putstr_fd("pb\n", 1);
}
