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
void ft_push(struct stack_node **head, int data)
{
    struct stack_node *new_node;

    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(!new_node)
    {
        free(new_node);
        return ;
    }
    new_node->data = data;

    new_node->next = (*head);
    new_node->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = new_node;

    (*head) = new_node;
}

void ft_add_after(struct stack_node *prv_node, int data)
{
    if (prv_node == NULL)
        return ;
    struct stack_node *new_node;

    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->next = prv_node->next;
    prv_node->next = new_node;
    new_node->prev = prv_node;

    if(new_node->next != NULL)
        new_node->next->prev = new_node;
}

void ft_add_before(struct stack_node **head, struct stack_node *nxt_node, int data)
{
    if(nxt_node == NULL)
        return ;
    struct stack_node *new_node;

    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->prev = nxt_node->prev;
    nxt_node->prev = new_node;
    new_node->next = nxt_node;

    if(new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head) = new_node;
}

void ft_add_end(struct stack_node **head, int data)
{
    struct stack_node *new_node;
    struct stack_node *last;

    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return ; 
}

void ft_pop(struct stack_node **head, struct stack_node *node)
{
    if((*head) == NULL || node == NULL)
        printf("stack is empty");
    if((*head) == node)
        (*head) = node->next;
    if(node->next != NULL)
        node->next->prev = node->prev;
    if(node->prev != NULL)
        node->prev->next = node->next;
    free(node);
    return;
}

stack_node *ft_peek(stack_node *head)
{
    stack_node *first;

    first = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(head == NULL)
        return (NULL);
    if(head->prev == NULL)
    {
        first->prev = NULL;
        first->data = head->data;
        first->next = NULL;
    }
    return(first);
}

stack_node *ft_end(stack_node *head)
{
    stack_node *last;

    last = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(head == NULL)
        return (NULL);
    last = head;
    while (last->next != NULL)
        last = last->next;
    return(last);
}

size_t ft_stacksize(stack_node *node)
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

void ft_printlist(struct stack_node *node)
{
    struct stack_node *last;
    while(node != NULL)
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
            "   %snext: %p%s\n" \
            "o-----------------------o\n", \
            BLU, \
            CYN, node, BLU, \
            YEL, node->prev, BLU, \
            RED, node->data, BLU, \
            RED, node->index, BLU, \
            RED, node->lenth, BLU, \
            RED, node->subsequence, BLU, \
            RED, node->chk, BLU, \
            GRN,node->next, BLU);
        if (node->next)
            printf("\t\\/\t/\\\n\t||\t||\n\t\\/\t/\\\n");
        // ft_putnbr_fd(node->data,1);
        last = node;
        node = node ->next;
    }
}
/*--------------------------------------utils------------------------------------------*/