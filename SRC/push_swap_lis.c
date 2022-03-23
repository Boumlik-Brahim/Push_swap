/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:08:06 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/22 12:08:08 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*--------------------------------------LIS------------------------------------------*/
void ft_index(t_stack *stack_a)
{
    int i;
    t_stack_node *current;

    i = 0;
    current = stack_a->head;
    while (current)
    {
        current->index = i;
        current = current->next;
        i++;
    }
}

void ft_instructions_number(t_stack *stack_a)
{
    t_stack_node *current;

    ft_index(stack_a);
    current = stack_a->head;
    while (current)
    {
        if (stack_a->size == 1)
            current->nmbr_of_instr = 0;
        else if (current->index < (stack_a->size / 2))
            current->nmbr_of_instr = current->index;
        else
            current->nmbr_of_instr = (stack_a->size - current->index) * -1;
        current = current->next;
    }
}

int ft_min_data(t_stack *stack)
{
    t_stack_node *tmp;
    int min_data;

    tmp = stack->head;
    min_data = tmp->data;
    while (tmp)
    {
        if (tmp->data < min_data)
            min_data = tmp->data;
        tmp = tmp->next;
    }
    return(min_data);
}


void ft_put_min_in_top(t_stack *stack)
{
    t_stack_node *current;
    int min_data;

    min_data = ft_min_data(stack);
    current = stack->head;
    while (current)
    {
        if (current->index < (stack->size / 2))
        {
            if (current->data == min_data)
            {
                int i;
                i = 0;
                while(i++ < current->nmbr_of_instr)
                    ft_ra(stack);
                ft_instructions_number(stack);
            }
        }
        else if (current->index > (stack->size / 2))
        {
            if (current->data == min_data)
            {
                int j;
                j = 0;
                while(j++ < my_abs(current->nmbr_of_instr))
                    ft_rra(stack);
                ft_instructions_number(stack);
            }
        }
        current = current->next;
    }
}

void ft_index_lenght(t_stack *stack_a)
{
    t_stack_node *current;
    t_stack_node *prev;
    int		nmber_befor;
	int		index_befor;
    
    current = stack_a->head->next;
    while (current)
    {
        prev = stack_a->head;
        while (prev != current)
        {
            if (prev->data < current->data)
            {
                if(prev->lenth + 1 > current->lenth)
                {
                    current->lenth = prev->lenth + 1;
                    current->subsequence = prev->index;
                    nmber_befor = prev->data;
                    index_befor = prev->index;
                }
                else if (prev->lenth + 1 == current->lenth)
                {
                    if(prev->data < nmber_befor)
                        current->subsequence = prev->index;
                    else
                        current->subsequence = index_befor;
                }
            }
            prev = prev->next;
        }
        current = current->next;
    }
}

void ft_LIS(t_stack *stack_a)
{
	int i;
	i = 0;
    t_stack_node  *current;
    t_stack_node  *lis;
    t_stack_node  *nxt;
    current = stack_a->head;
    while (i++ < stack_a->size / 2)
    {
        nxt = stack_a->head->next;
        while (nxt)
        {
            if (current->lenth < nxt->lenth)
                lis = nxt;
            nxt = nxt->next;
        }
        current = current->next;
    }
	i = stack_a->size;
    current = stack_a->tail;
    while (i-- >= stack_a->size / 2)
    {
        if (current->lenth == lis->lenth)
            current->chk = 1;
        if (current->index == lis->subsequence)
        {
            current->chk = 1;
            lis->subsequence = current->subsequence;
        }
        current = current->prev;
    }
}

int my_abs(int nbr)
{
    if (nbr < 0)
        return (nbr * -1);
    return (nbr);
}

int ft_first_mv(t_stack *stack_a)
{
    int node_instr;
    t_stack_node    *tmp_node;
    int             i;

    node_instr = stack_a->size / 2;
    tmp_node = stack_a->head;
    i = -1;
    while (++i < stack_a->size)
    {
        if (tmp_node->chk == 0 && my_abs(tmp_node->nmbr_of_instr) <= my_abs(node_instr))
            node_instr = tmp_node->nmbr_of_instr;
        tmp_node = tmp_node->next;
    }
    return (node_instr);
}

void ft_push_b(t_stack *stack_a,t_stack *stack_b)
{
    t_stack_node *current;

    current = stack_a->head;
    while(current)
    {
        ft_index(stack_a);
        ft_instructions_number(stack_a);
        if (ft_first_mv(stack_a) >= 0 && current->nmbr_of_instr == ft_first_mv(stack_a))
        {
            while (current->nmbr_of_instr--)
                ft_ra(stack_a);
            ft_pb(stack_a,stack_b);
            current = stack_a->head;
        }
        else if (ft_first_mv(stack_a) < 0 && current->nmbr_of_instr == ft_first_mv(stack_a))
        {
            while (current->nmbr_of_instr++)
                ft_rra(stack_a);
            ft_pb(stack_a,stack_b);
            current = stack_a->head;
        }
        else
            current = current->next; 
    }
}
/*--------------------------------------LIS------------------------------------------*/