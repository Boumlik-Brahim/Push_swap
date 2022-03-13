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
// void ft_sa(stack_node *sa)
// {
//     stack_node *tmp;

//     if (ft_stacksize(sa) <= 1)
//         return ;
//     tmp  = ft_peek(sa);
// }

void ft_sa(stack_node **sa)
{
    if (ft_stacksize(*sa) <= 1)
        return ;
    if((*sa)->prev == NULL)
        ft_swap(&(*sa)->data,&(*sa)->next->data);
    ft_putstr_fd("sa\n", 1);
}

void ft_sb(stack_node **sb)
{
    if (ft_stacksize(*sb) <= 1)
        return ;
    if((*sb)->prev == NULL)
        ft_swap(&(*sb)->data,&(*sb)->next->data);
    ft_putstr_fd("sb\n", 1);
}

void	ft_ss(stack_node **sa, stack_node **sb)
{
	ft_sa(sa);
	ft_sb(sb);
}

void ft_ra(stack_node **ra)
{
    if ((*ra) == NULL || ft_stacksize(*ra) <= 1)
		return ;
    stack_node *tmp;
    tmp = (*ra);
    while (tmp)
    {   
        if (tmp->prev == NULL)
            ft_swap(&tmp->data,&tmp->next->data);
        else if (tmp->next)
            ft_swap(&tmp->data,&tmp->next->data);
        tmp = tmp->next;
    }
    ft_putstr_fd("ra\n", 1);
}

void ft_rb(stack_node **rb)
{
    if ((*rb) == NULL || ft_stacksize(*rb) <= 1)
		return ;
    stack_node *tmp;
    tmp = (*rb);
    while (tmp)
    {   
        if (tmp->prev == NULL)
            ft_swap(&tmp->data,&tmp->next->data);
        else if (tmp->next)
            ft_swap(&tmp->data,&tmp->next->data);
        tmp = tmp->next;
    }
    ft_putstr_fd("rb\n", 1);
}

void	ft_rr(stack_node **ra, stack_node **rb)
{
	ft_ra(ra);
	ft_rb(rb);
}

void ft_rra(stack_node **rra)
{
    stack_node *tmp;
    stack_node *current;

    if ((*rra) == NULL || ft_stacksize(*rra) <= 1)
		return ;
    tmp = NULL;
    current = ft_end(*rra);
    while (current)
    {
        if (current->next == NULL)
            ft_swap(&current->data,&current->prev->data);   
        else if (current->prev)
            ft_swap(&current->data,&current->prev->data);
        current = current->prev;
    }
    ft_putstr_fd("rra\n", 1);
}

void ft_rrb(stack_node **rrb)
{
    stack_node *tmp;
    stack_node *current;

    if ((*rrb) == NULL || ft_stacksize(*rrb) <= 1)
		return ;
    tmp = NULL;
    current = ft_end(*rrb);
    while (current)
    {
        if (current->next == NULL)
            ft_swap(&current->data,&current->prev->data);   
        else if (current->prev)
            ft_swap(&current->data,&current->prev->data);
        current = current->prev;
    }
    ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(stack_node **rra, stack_node **rrb)
{
	ft_rra(rra);
	ft_rrb(rrb);
}

void ft_pa(stack_node **pa,stack_node **pb)
{
    stack_node *tmp;

    if (ft_peek(*pb) == NULL)
        return ;
    tmp  = ft_peek(*pb);
    tmp->next = (*pa);
    tmp->prev = NULL;
    (*pa) = tmp;
}

void ft_pb(stack_node **pa,stack_node **pb)
{
    stack_node *tmp;

    if (ft_peek(*pa) == NULL)
        return ;
    tmp  = ft_peek(*pa);
    tmp->next = (*pb);
    tmp->prev = NULL;
    (*pb) = tmp;
}
/*--------------------------------------instructions------------------------------------------*/
