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

/* -------------------------------------------------------------------------- */

int ft_min_data_a(t_stack *stack_a)
{
    t_stack_node *tmp;
    int min_data;
    int i;
    i = -1;
    tmp = stack_a->head;
    min_data = tmp->data;
    while (++i < stack_a->size)
    {
        if (tmp->data < min_data)
        {
            min_data = tmp->data;
        }
        tmp = tmp->next;
    }
    return(min_data);
}

/* -------------------------------------------------------------------------- */

int ft_min_data_nbr_istr(t_stack *stack_a)
{
    t_stack_node *tmp;
    int min_data;
    int min_data_instruction;
    int i;
    i = -1;
    tmp = stack_a->head;
    min_data = ft_min_data_a(stack_a);
    while (++i < stack_a->size)
    {
        if (tmp->data == min_data)
            min_data_instruction = tmp->nmbr_of_instr;
        tmp = tmp->next;
    }
    return(min_data_instruction);
}

/* -------------------------------------------------------------------------- */

int ft_max_data(t_stack *stack_a)
{
    t_stack_node *tmp;
    int max_data;
    int i;
    i = -1;
    tmp = stack_a->head;
    max_data = tmp->data;
    while (++i < stack_a->size)
    {
        if (tmp->data > max_data)
        {
            max_data = tmp->data;
        }
        tmp = tmp->next;
    }
    return(max_data);
}

/* -------------------------------------------------------------------------- */

int ft_max_data_nbr_istr(t_stack *stack_a)
{
    t_stack_node *tmp;
    int max_data;
    int max_data_instruction;
    int i;
    i = -1;
    tmp = stack_a->head;
    max_data = ft_max_data(stack_a);
    while (++i < stack_a->size)
    {
        if (tmp->data == max_data)
            max_data_instruction = tmp->nmbr_of_instr + 1;
        tmp = tmp->next;
    }
    return(max_data_instruction);
}

/* -------------------------------------------------------------------------- */

int get_best_move_stack_a(int data, t_stack *stack_a)
{
    t_stack_node *current_a;
    int          i;

    i = 0;
    current_a = stack_a->head;
    while (current_a->next)
    {
        if (current_a->data < data && current_a->next->data > data)
        {
            if (i <= stack_a->size / 2)
                return (i);
            else
                return ((stack_a->size - i) * -1);
        }
        current_a = current_a->next;
        i++;
    }
    return (i);
}

/* -------------------------------------------------------------------------- */

int get_total_moves(int moves_a, int moves_b)
{
    if ((moves_a >= 0 && moves_b >= 0) || (moves_a < 0 && moves_b < 0))
    {
        if (my_abs(moves_a) > my_abs(moves_b))
            return (my_abs(moves_a));
        else
            return (my_abs(moves_b));
    }
    return (my_abs(moves_a) + my_abs(moves_b));
}

/* -------------------------------------------------------------------------- */

void ft_best_element_in_b(t_stack *stack_a,t_stack *stack_b)
{
    t_stack_node *current_b;
    int             i;

    current_b = stack_b->head;
    i = 0;
    while(current_b)
    {
        current_b->tmp[0] = get_best_move_stack_a(current_b->data, stack_a);
        if (i <= stack_b->size / 2)
            current_b->tmp[1] = i;
        else
            current_b->tmp[1] = (stack_b->size - i) * -1;
        current_b->nmbr_of_instr = get_total_moves(current_b->tmp[0], current_b->tmp[1]);
        current_b = current_b->next;
        i++;
    }
}

/* -------------------------------------------------------------------------- */

void ft_first_mv_sb(t_stack *stack_a, t_stack *stack_b, t_best_mv *best)
{
    t_stack_node    *tracer;
    t_stack_node    *node;

    ft_best_element_in_b(stack_a, stack_b);
    node = stack_b->head;

    tracer = stack_b->head;
    while (tracer)
    {
       
        tracer = tracer->next;
    }
}

/* -------------------------------------------------------------------------- */

// void ft_first_mv_sb(t_stack *stack_a,t_stack *stack_b, t_best_mv *best)
// {
//     t_stack_node    *tmp_node;
//     int             node_instr;
//     int             i;
    
//     // ft_max_data_nbr_istr(stack_a);
//     // ft_instructions_number(stack_a);
//     ft_best_element_in_b(stack_a,stack_b);
    
//     tmp_node = stack_b->head;
//     node_instr = my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1]);
//     best->data = tmp_node->data;
//     best->index = tmp_node->index;
//     best->nmb_inst = tmp_node->tmp[0];
//     best->nmb_inst_b = tmp_node->tmp[1];
//     i = -1;
//     while (++i < stack_b->size)
//     {
//         if ((my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1])) < my_abs(node_instr))
//         {
//             node_instr = my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1]);
//             best->data = tmp_node->data;
//             best->index = tmp_node->index;
//             best->nmb_inst = tmp_node->tmp[0];
//             best->nmb_inst_b = tmp_node->tmp[1];
//         }
//         tmp_node = tmp_node->next;
//     }
// }

void ft_push_a(t_stack *stack_a,t_stack *stack_b)
{
    t_best_mv best; 
    t_stack_node *current_b;
    current_b = stack_b->head;

    ft_first_mv_sb(stack_a,stack_b, &best);
    // printf("data = %d | nmb_ins = %d | nmb_ins_b = %d\n", best.data, best.nmb_inst, best.nmb_inst_b);
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
        ft_first_mv_sb(stack_a,stack_b, &best);
        // break ;
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

        ft_printlist(&stack_a);
    }
    else
        ft_handle_error("INVALID ARGUMENT");
    return(0);
}
/*--------------------------------------main------------------------------------------*/