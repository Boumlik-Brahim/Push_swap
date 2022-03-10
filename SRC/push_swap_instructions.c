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
void ft_sa(stack_node **sa)
{
    stack_node *tmp;

    tmp  = ft_peek(*sa);
    if((*sa)->prev == NULL)
    {
        ft_add_after((*sa)->next,tmp->data);
        ft_pop(sa,*sa);
    }
}

void ft_sb(stack_node **sb)
{
    stack_node *tmp;

    tmp  = ft_peek(*sb);
    if((*sb)->prev == NULL)
    {
        ft_add_after((*sb)->next,tmp->data);
        ft_pop(sb,*sb);
    }
}

void	ft_ss(stack_node **sa, stack_node **sb)
{
	ft_sa(sa);
	ft_sb(sb);
}

void ft_ra(stack_node **ra)
{
    stack_node *tmp;

    tmp  = ft_peek(*ra);
    if((*ra)->prev == NULL)
    {
        ft_add_end(ra,tmp->data);
        ft_pop(ra,*ra);
    }
}

void ft_rb(stack_node **rb)
{
    stack_node *tmp;

    tmp  = ft_peek(*rb);
    if((*rb)->prev == NULL)
    {
        ft_add_end(rb,tmp->data);
        ft_pop(rb,*rb);
    }
}

void	ft_rr(stack_node **ra, stack_node **rb)
{
	ft_ra(ra);
	ft_rb(rb);
}

void ft_rra(stack_node **rra)
{
    stack_node *last;
    stack_node *tmp;

    tmp  = ft_end(*rra);
    last  = (*rra);
    if((*rra)->prev == NULL)
        ft_push(rra,tmp->data);
    while (last->next != NULL)
        last = last->next;
    ft_pop(&last,last);
}

void ft_rrb(stack_node **rrb)
{
    stack_node *last;
    stack_node *tmp;

    tmp  = ft_end(*rrb);
    last  = (*rrb);
    if((*rrb)->prev == NULL)
        ft_push(rrb,tmp->data);
    while (last->next != NULL)
        last = last->next;
    ft_pop(&last,last);
}

void	ft_rrr(stack_node **rra, stack_node **rrb)
{
	ft_rra(rra);
	ft_rrb(rrb);
}

void ft_pa(stack_node **pa,stack_node **pb)
{
    stack_node *tmp;

    tmp  = ft_peek(*pb);
    ft_push(pa,tmp->data);
}

void ft_pb(stack_node **pa,stack_node **pb)
{
    stack_node *tmp;

    tmp  = ft_peek(*pa);
    ft_push(pb,tmp->data);
}
/*--------------------------------------instructions------------------------------------------*/
