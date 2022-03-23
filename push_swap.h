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

typedef struct s_stack_node
{
    struct s_stack_node *prev;
    int data;
    int index;
    int lenth;
    int subsequence;
    int chk;
    int nmbr_of_instr;
    int tmp[2];
    struct s_stack_node *next;
} t_stack_node;

typedef struct s_stack {
    t_stack_node  *head;
    t_stack_node  *tail;
    int         size;
}   t_stack;

typedef struct s_best_mv
{
    int data;
    int index;
    int nmb_inst;
    int nmb_inst_b;
}   t_best_mv;

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

void ft_init_node(t_stack_node *node, int data);
void ft_push(t_stack *stack, int data);
void ft_printlist(t_stack  *node);

void ft_index(t_stack *stack_a);
void ft_instructions_number(t_stack *stack_a);
int ft_min_data(t_stack *stack);
// int ft_min_data(t_stack *stack, t_stack_node **min_node);
void ft_put_min_in_top(t_stack *stack);
void ft_index_lenght(t_stack *stack_a);
void ft_LIS(t_stack *stack_a);
int my_abs(int nbr);
int ft_first_mv(t_stack *stack_a);
void ft_push_b(t_stack *stack_a,t_stack *stack_b);

#endif