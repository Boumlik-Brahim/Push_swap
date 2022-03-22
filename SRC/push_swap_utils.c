/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:21:21 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/09 20:21:23 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*--------------------------------------utils------------------------------------------*/
void    ft_init_node(t_stack_node *node, int data)
{
    node->data = data;
    node->index = 0;
    node->lenth = 1;
    node->subsequence = 0;
    node->chk = 0;
    node->nmbr_of_instr = 0;
    node->tmp[0] = 0;
    node->tmp[1] = 0;
}

void ft_push(t_stack *stack, int data)
{
    t_stack_node *new_node;

    new_node = (t_stack_node *) malloc(sizeof(t_stack_node));
    if (!new_node)
        return ;
    if (stack->size == 0)
    {
        stack->head = new_node;
        stack->tail = new_node;
        stack->tail->next = NULL;
    }
    else
    {
        stack->head->prev = new_node;
        new_node->next = stack->head;
        stack->head = new_node;
    }
    ft_init_node(new_node,data);
    stack->head->prev = NULL;
    stack->size += 1;
}

void ft_printlist(t_stack  *node)
{
    t_stack_node *last;
    while(node->head != NULL)
    {
        printf("%so-----------------------o\n" \
            "| %s%p\t%s|\n" \
            "o-----------------------o\n" \
            "   %sprev: %p%s\n" \
            "   %sdata: %d%s\n" \
            "   %sIndex: %d%s\n" \
            "   %sLenght: %d%s\n" \
            "   %sSubsequence: %d%s\n" \
            "   %sChk: %d%s\n" \
            "   %sinst_nmbr: %d%s\n" \
            "   %stmp[0]: %d%s\n" \
            "   %stmp[1]: %d%s\n" \
            "   %snext: %p%s\n" \
            "o-----------------------o\n", \
            BLU, \
            CYN, node->head, BLU, \
            YEL, node->head->prev, BLU, \
            RED, node->head->data, BLU, \
            RED, node->head->index, BLU, \
            RED, node->head->lenth, BLU, \
            RED, node->head->subsequence, BLU, \
            RED, node->head->chk, BLU, \
            RED, node->head->nmbr_of_instr, BLU, \
            RED, node->head->tmp[0], BLU, \
            RED, node->head->tmp[1], BLU, \
            GRN,node->head->next, BLU);
        if (node->head->next)
            printf("\t\\/\t/\\\n\t||\t||\n\t\\/\t/\\\n");
        last = node->head;
        node->head = node->head->next;
    }
}

size_t ft_stacksize(t_stack_node *node)
{
	size_t	i;

	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*--------------------------------------utils------------------------------------------*/