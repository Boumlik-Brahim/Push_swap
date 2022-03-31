/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:48:15 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 20:43:49 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *sa)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (sa->size > 2)
	{
		tmp = sa->head->next;
		tmp2 = tmp->next;
		tmp->next = sa->head;
		sa->head->prev = tmp;
		sa->head->next = tmp2;
		tmp2->prev = sa->head;
		sa->head = tmp;
		sa->head->prev = NULL;
	}
	else if (sa->size == 2)
	{
		sa->tail = sa->head;
		sa->head = sa->head->next;
		sa->head->next = sa->tail;
		sa->tail->prev = sa->head;
		sa->tail->next = NULL;
		sa->head->prev = NULL;
	}
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *sb)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (sb->size > 2)
	{
		tmp = sb->head->next;
		tmp2 = tmp->next;
		tmp->next = sb->head;
		sb->head->prev = tmp;
		sb->head->next = tmp2;
		tmp2->prev = sb->head;
		sb->head = tmp;
		sb->head->prev = NULL;
	}
	else if (sb->size == 2)
	{
		sb->tail = sb->head;
		sb->head = sb->head->next;
		sb->head->next = sb->tail;
		sb->tail->prev = sb->head;
		sb->tail->next = NULL;
		sb->head->prev = NULL;
	}
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *sa, t_stack *sb)
{
	ft_sa(sa);
	ft_sb(sb);
}
