/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:21:32 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/09 20:21:34 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*--------------------------------------instructions------------------------------------------*/
void ft_sa(t_stack *sa)
{
    stack_node *tmp;
    stack_node *tmp2;
    if (sa->size <= 1)
        return ;
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

void ft_sb(t_stack *sb)
{
    if (sb->size <= 1)
        return ;
    stack_node *tmp;
    stack_node *tmp2;
    if (sb->size <= 1)
        return ;
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

void ft_ra(t_stack *ra)
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

void ft_rb(t_stack *rb)
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
	ft_ra(ra);
	ft_rb(rb);
}

void ft_rra(t_stack *rra)
{
    stack_node *tmp;

    if (rra->size <= 1)
        return ;
    tmp = rra->tail;
    tmp->next = rra->head;
    rra->head->prev = tmp;
    rra->tail->prev->next = NULL;
    rra->head = tmp;
    rra->head->prev = NULL;
    ft_putstr_fd("rra\n", 1);
}

void ft_rrb(t_stack *rrb)
{
    stack_node *tmp;

    if (rrb->size <= 1)
        return ;
    tmp = rrb->tail;
    tmp->next = rrb->head;
    rrb->head->prev = tmp;
    rrb->tail->prev->next = NULL;
    rrb->head = tmp;
    rrb->head->prev = NULL;
    ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *rra, t_stack *rrb)
{
	ft_rra(rra);
	ft_rrb(rrb);
}

void ft_pa(t_stack *pa,t_stack *pb)
{
    stack_node *tmp;
    stack_node *tmp2;

    if (pb->head == NULL)
        return ;
    if (pb->size >= 1 && pa->size != 0)
	{
		tmp = pb->head;
		tmp2 = pa->head;
		pb->head = pb->head->next;
		tmp->next = tmp2;
		tmp2->prev = tmp;
		pa->head = tmp;
		pa->size++;
		pb->size--;
	}
	else if (pa->size == 0)
	{
		tmp = pb->head;
		pa->head = pb->head;
		pb->head = tmp->next;
		pa->head->data = tmp->data;
		pa->head->next = NULL;
		pa->tail = pa->head;
		pa->size++;
		pb->size--;
	}
    ft_putstr_fd("pa\n", 1);
}

void ft_pb(t_stack *pa,t_stack *pb)
{
    // stack_node *tmp;
    pb = NULL;
    if (pa->head == NULL)
        return ;
    
    ft_putstr_fd("pb\n", 1);
}
/*--------------------------------------instructions------------------------------------------*/
