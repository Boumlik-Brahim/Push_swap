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

void ft_is_betwen_head_tail(t_stack_node *stack_b,t_stack *stack_a)
{
    t_stack_node *current_head_a;
    t_stack_node *current_tail_a;

    current_head_a = stack_a->head;
    current_tail_a = stack_a->tail;
    if (stack_b->data < current_head_a->data && stack_b->data > current_tail_a->data)
    {
        stack_b->tmp[0] = current_head_a->nmbr_of_instr;
        stack_b->tmp[1] = stack_b->nmbr_of_instr;
    }
}

int ft_max_data_nbr_istr(t_stack *stack_a)
{
    t_stack_node *tmp;
    int max_data;
    int max_data_instruction;
    int i;
    i = -1;
    tmp = stack_a->head;
    max_data = tmp->data;
    while (++i < stack_a->size)
    {
        if (tmp->data > max_data)
        {
            max_data = tmp->data;
            max_data_instruction = tmp->nmbr_of_instr;
        }
        tmp = tmp->next;
    }
    // printf("max data:        %d          instr:%d\n", max_data, max_data_instruction);
    return(max_data_instruction);
}

void ft_best_element_in_b(t_stack *stack_a,t_stack *stack_b)
{
    ft_instructions_number(stack_a);
    ft_instructions_number(stack_b);

    t_stack_node *current_head_a;
    t_stack_node *current_next_a;

    t_stack_node *current_tail_a;
    t_stack_node *current_prev_a;
    
    t_stack_node * current_b;
    current_b = stack_b->head;
    while (current_b)
    {
        ft_is_betwen_head_tail(current_b,stack_a);
        int i;
        i = 0;
        current_head_a = stack_a->head;
        while(current_head_a && ++i < (stack_a->size / 2))
        {
            current_next_a = current_head_a->next;
            while (current_next_a && i < (stack_a->size / 2))
            {
                if (current_b->data > current_head_a->data && current_b->data < current_next_a->data)
                {
                    current_b->tmp[0] = current_head_a->next->nmbr_of_instr;
                    current_b->tmp[1] = current_b->nmbr_of_instr;
                }
                else if (current_b->data >= 9 && current_b->nmbr_of_instr >= 0)
                {
                    current_b->tmp[0] = ft_max_data_nbr_istr(stack_a) + 1;
                    // printf("%d\n",ft_max_data_nbr_istr(stack_a) + 1);
                    current_b->tmp[1] = current_b->nmbr_of_instr;
                }
                current_next_a = current_next_a->next;
                break;
            }
            current_head_a = current_head_a->next;
        }
        int j;
        j = stack_a->size;
        current_tail_a = stack_a->tail;
        while(current_tail_a && --j > (stack_a->size / 2))
        {
            current_prev_a = current_tail_a->prev;
            while (current_prev_a && j > (stack_a->size / 2))
            {
                if (current_b->data > current_prev_a->data && current_b->data < current_tail_a->data)
                {
                    current_b->tmp[0] = current_prev_a->nmbr_of_instr;
                    current_b->tmp[1] = current_b->nmbr_of_instr;
                }
                else if (current_b->data >= 9 && current_b->nmbr_of_instr < 0)
                {
                    current_b->tmp[0] = ft_max_data_nbr_istr(stack_a) - 1;
                    current_b->tmp[1] = current_b->nmbr_of_instr;
                }
                current_prev_a = current_prev_a->prev;
                break;
            }
            current_tail_a = current_tail_a->prev;
        }
        current_b = current_b->next;
    }
}


void ft_first_mv_sb(t_stack *stack_a,t_stack *stack_b, t_best_mv *best)
{
    t_stack_node    *tmp_node;
    int             node_instr;
    int             i;
    
    ft_max_data_nbr_istr(stack_a);
    ft_instructions_number(stack_a);
    ft_best_element_in_b(stack_a,stack_b);
    
    tmp_node = stack_b->head;
    node_instr = my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1]);
    best->data = tmp_node->data;
    best->index = tmp_node->index;
    best->nmb_inst = tmp_node->tmp[0];
    i = -1;
    while (++i < stack_b->size)
    {
        if ((my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1])) < my_abs(node_instr))
        {
            if(tmp_node->tmp[0] > 0 && tmp_node->tmp[1] > 0)
            {
                if (tmp_node->tmp[0] > tmp_node->tmp[1])
                {

                }
                if (tmp_node->tmp[0] < tmp_node->tmp[1])
                {
                    
                }
            }
            else if(tmp_node->tmp[0] < 0 && tmp_node->tmp[1] < 0)
            {
                if (tmp_node->tmp[0] > tmp_node->tmp[1])
                {

                }
                if (tmp_node->tmp[0] < tmp_node->tmp[1])
                {

                }
            }
            else if (tmp_node->tmp[0] == tmp_node->tmp[1])
            {
                printf("%d\n",tmp_node->tmp[0]);
                printf("%d\n",tmp_node->tmp[1]);
            }
            node_instr = my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1]);
            best->data = tmp_node->data;
            best->index = tmp_node->index;
            best->nmb_inst = tmp_node->tmp[0];
        }
        tmp_node = tmp_node->next;
    }
}

void ft_push_a(t_stack *stack_a,t_stack *stack_b)
{
    t_best_mv best; 
    t_stack_node *current_b;
    current_b = stack_b->head;

    // ft_max_data_nbr_istr(stack_a);
    // ft_best_element_in_b(stack_a,stack_b);
    ft_first_mv_sb(stack_a,stack_b, &best);
    while(current_b->data != best.data)
    {
        if(best.index < (stack_b->size / 2))
            ft_rb(stack_b);
        else
            ft_rrb(stack_b);
        current_b = stack_b->head;
    }
    while(stack_b->size != 0)
    {
        if(best.nmb_inst >= 0)
        {
            while(best.nmb_inst != 0)
            {
                ft_ra(stack_a);
                best.nmb_inst--;
            }
            ft_pa(stack_a, stack_b);
        }
        else if (best.nmb_inst < 0)
        {
            int j = my_abs(best.nmb_inst);
            while ( j != 0)
            {
                ft_rra(stack_a);
                j--;
            }
            ft_pa(stack_a, stack_b);
        }
        if(stack_b->size == 0)
            break ;
        // ft_max_data_nbr_istr(stack_a);
        // ft_best_element_in_b(stack_a,stack_b);
        ft_first_mv_sb(stack_a,stack_b, &best);
        while(current_b->data != best.data)
        {
            if (best.index < (stack_b->size / 2))
                ft_rb(stack_b);
            else
                ft_rrb(stack_b);
            current_b = stack_b->head;
        }
    }
    // ft_printlist(stack_b);
}
/*--------------------------------------main------------------------------------------*/
int main(int ac, char **av)
{
    t_stack     stack_a;
    t_stack     stack_b;
    int         i;

    stack_a.size = 0;
    stack_b.size = 0;
    i = ac;
    if(ac >= 2)
    {
        int a;
        while(--i)
        {
            if(av[i][0] == '\0')
                ft_handle_error("EMPTY ARGUMENT");
            a = ft_atoi(av[i]);
            ft_push(&stack_a,a);           
        }
        ft_instructions_number(&stack_a);
        ft_put_min_in_top(&stack_a);
        ft_index_lenght(&stack_a);
        ft_LIS(&stack_a);
        ft_push_b(&stack_a,&stack_b);
        ft_best_element_in_b(&stack_a,&stack_b);
        ft_push_a(&stack_a,&stack_b);
        ft_instructions_number(&stack_a);
        ft_put_min_in_top(&stack_a);

        // ft_ra(&stack_a);
        // ft_pa(&stack_a,&stack_b);
        // ft_best_element_in_b(&stack_a,&stack_b);
        // ft_rrb(&stack_b);
        // ft_pa(&stack_a,&stack_b);
        // ft_best_element_in_b(&stack_a,&stack_b);
        // ft_ra(&stack_a);
        // ft_rrb(&stack_b);
        // ft_pa(&stack_a,&stack_b);
        // ft_best_element_in_b(&stack_a,&stack_b);
        // ft_ra(&stack_a);
        // ft_ra(&stack_a);
        // ft_ra(&stack_a);
        // ft_ra(&stack_a);
        // ft_pa(&stack_a,&stack_b);

        // ft_printlist(&stack_a);
    }
    else
        ft_handle_error("INVALID ARGUMENT");
    return(0);
}
/*--------------------------------------main------------------------------------------*/