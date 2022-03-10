/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:07:14 by bbrahim           #+#    #+#             */
/*   Updated: 2022/02/17 11:07:19 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*--------------------------------------error_management------------------------------------------*/
void	ft_handle_error(char *str)
{
	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
	ft_putstr_fd(str, 1);
	exit(0);
}
/*--------------------------------------error_management------------------------------------------*/

/*--------------------------------------LIS------------------------------------------*/
void ft_index_lenght(stack_node *stack_a)
{
    stack_node *current;
    stack_node *prev;
    int		nmber_befor;
	int		index_befor;
    
    current = stack_a->next;
    while (current)
    {
        prev = stack_a;
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

stack_node *get_stack_node_by_index(stack_node *stack_node, int index)
{
    int i;

    i = 0;
    while (i++ != index && stack_node)
        stack_node = stack_node->next;
    return (stack_node);
}

void ft_LIS(stack_node *stack_a)
{
    stack_node  *tmp_node;
    stack_node  *head;

    head = stack_a;
    tmp_node = stack_a;
    stack_a = stack_a->next;
    while (stack_a)
    {
        if (tmp_node->lenth < stack_a->lenth)
            tmp_node = stack_a;
        stack_a = stack_a->next;
    }
    stack_a = tmp_node;
    while (tmp_node->subsequence >= 0)
    {
        tmp_node->chk = 1;
        tmp_node = get_stack_node_by_index(head, tmp_node->subsequence);
    }
    tmp_node->chk = 1;
}

void ft_puch_b(stack_node **stack_a,stack_node **stack_b)
{
    stack_node *current;

    current = *stack_a;
    while (current)
    {
        if (current->chk == 0)
        {
            (*stack_b)->next = current;
            current->prev = (*stack_b);
        }
        current = current->next;
    }
}
/*--------------------------------------LIS------------------------------------------*/

/*--------------------------------------main------------------------------------------*/
int main(int ac, char **av)
{
    stack_node *stack_a;
    stack_node *stack_b;

    stack_a = NULL;
    // stack_a->prev = NULL;
    // stack_a->data = 0;
    // stack_a->next = NULL;
    
    stack_b = NULL;
    // stack_b->prev = NULL;
    // stack_b->data = 0;
    // stack_b->next = NULL;

    if(ac >= 2)
    {
        // int i;
        int a;

        // i = 0;
        while(--ac)
        {
            if(av[ac][0] == '\0')
                ft_handle_error("EMPTY ARGUMENT");
            a = ft_atoi(av[ac]);
            ft_push(&stack_a,a);
            stack_a->lenth = 1;
            stack_a->subsequence = -1;
            stack_a->index = ac - 1;
            stack_a->chk = 0; 
        }
        // ft_sa(&stack_a);
        // ft_ra(&stack_a);
        // ft_rra(&stack_a);
        // pa(&stack_a,&stack_b);
        // pb(&stack_a,&stack_b);
        ft_index_lenght(stack_a);
        ft_LIS(stack_a);
        ft_puch_b(&stack_a,&stack_b);
        ft_printlist(stack_a);
        printf("\no                       o\n");
        printf("\no----------a------------o\n");
        printf("\no                       o\n");
        ft_printlist(stack_b);
        printf("\no                       o\n");
        printf("\no----------b------------o\n");
        printf("\no                       o\n");
    }
    else
        ft_handle_error("INVALID ARGUMENT");
    return(0);
}
/*--------------------------------------main------------------------------------------*/