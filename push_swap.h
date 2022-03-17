/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:06:48 by bbrahim           #+#    #+#             */
/*   Updated: 2022/02/17 11:06:50 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include "Libft/libft.h"

# define BLD "\033[31;0m\033[1m"
# define NC "\033[31;0m"
# define RED "\033[31;0m\033[0;31;1m"
# define YEL "\033[31;0m\033[0;33;1m"
# define GRA "\033[31;0m\033[0;37;1m"
# define CYN "\033[31;0m\033[0;36;1m"
# define GRN "\033[31;0m\033[0;32;1m"
# define MGN "\033[31;0m\033[0;35;1m"
# define BLU "\033[31;0m\033[0;34;1m"

typedef struct stack_node
{
    struct stack_node *prev;
    int data;
    int index;
    int lenth;
    int subsequence;
    int chk;
    int nmbr_of_instr;
    struct stack_node *next;
} stack_node;

typedef struct s_stack {
    stack_node  *head;
    stack_node  *tail;
    int         size;
}   t_stack;

void ft_sa(t_stack *sa);
void ft_sb(t_stack *sb);
void ft_ss(t_stack *sa, t_stack *sb);
void ft_ra(t_stack *ra);
void ft_rb(t_stack *rb);
void ft_rr(t_stack *ra, t_stack *rb);
void ft_rra(t_stack *rra);
void ft_rrb(t_stack *rrb);
void ft_rrr(t_stack *rra, t_stack *rrb);
void ft_pa(t_stack *pa,t_stack *pb);
void ft_pb(t_stack *pa,t_stack *pb);

void	ft_handle_error(char *str);

void ft_init_node(stack_node *node, int data);
void ft_push(t_stack *stack, int data);
void ft_printlist(struct stack_node *node);
size_t ft_stacksize(stack_node *node);
void	ft_swap(int *a, int *b);

// void ft_index_lenght(stack_node *stack_a);
// stack_node *get_stack_node_by_index(stack_node *stack_node, int index);
// void ft_LIS(stack_node *stack_a);

stack_node *ft_peek(stack_node *head);
stack_node *ft_end(stack_node *head);
void ft_add_after(struct stack_node *prv_node, int data);
void ft_add_before(struct stack_node **head, struct stack_node *nxt_node, int data);
void ft_add_end(struct stack_node **head, int data);
void ft_pop(struct stack_node **head, struct stack_node *node);





#endif