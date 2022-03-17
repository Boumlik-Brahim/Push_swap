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

/*--------------------------------------LIS------------------------------------------*/

// void ft_index_lenght(stack_node *stack_a)
// {
//     stack_node *current;
//     stack_node *prev;
//     int		nmber_befor;
// 	int		index_befor;
    
//     current = stack_a->next;
//     while (current)
//     {
//         prev = stack_a;
//         while (prev != current)
//         {
//             if (prev->data < current->data)
//             {
//                 if(prev->lenth + 1 > current->lenth)
//                 {
//                     current->lenth = prev->lenth + 1;
//                     current->subsequence = prev->index;
//                     nmber_befor = prev->data;
//                     index_befor = prev->index;
//                 }
//                 else if (prev->lenth + 1 == current->lenth)
//                 {
//                     if(prev->data < nmber_befor)
//                         current->subsequence = prev->index;
//                     else
//                         current->subsequence = index_befor;
//                 }
//             }
//             prev = prev->next;
//         }
//         current = current->next;
//     }
// }

// stack_node *get_stack_node_by_index(stack_node *stack_node, int index)
// {
//     int i;

//     i = 0;
//     while (i++ != index && stack_node)
//         stack_node = stack_node->next;
//     return (stack_node);
// }

// void ft_LIS(stack_node *stack_a)
// {
//     stack_node  *tmp_node;
//     stack_node  *head;

//     head = stack_a;
//     tmp_node = stack_a;
//     stack_a = stack_a->next;
//     while (stack_a)
//     {
//         if (tmp_node->lenth < stack_a->lenth)
//             tmp_node = stack_a;
//         stack_a = stack_a->next;
//     }
//     stack_a = tmp_node;
//     while (tmp_node->subsequence >= 0)
//     {
//         tmp_node->chk = 1;
//         tmp_node = get_stack_node_by_index(head, tmp_node->subsequence);
//     }
//     tmp_node->chk = 1;
    
// }

// void ft_min_data(stack_node **head)
// {
//     stack_node *tmp;
//     stack_node *current;
//     int min_data;
//     size_t half_stack;
//     int indx;
//     int index;
//     int i;
//     int j;

//     tmp = (*head);
//     min_data = tmp->data;
//     half_stack = ft_stacksize(*head) / 2;
//     while (tmp)
//     {
//         if (tmp->data < min_data)
//             min_data = tmp->data;
//         tmp = tmp->next;
//     }
//     current = (*head);
//     while (current)
//     {
//         if (current->index < (int)half_stack)
//         {
//             if (current->data <= min_data)
//             {
//                 indx = current->index;
//                 i = 0;
//                 while(i++ < indx)
//                     ft_ra(head);
//             }
//         }
//         else
//         {
//             if (current->data <= min_data)
//             {
//                 index = current->index;
//                 j = 0;
//                 while(j++ < index)
//                     ft_rra(head);
//             }
//         }
//         current = current->next;
//     }
// }

// void ft_instructions_number(stack_node **stack_a)
// {
//     stack_node *current;
//     size_t half_stack;

//     current = (*stack_a);
//     half_stack = ft_stacksize(*stack_a) / 2;
//     while (current)
//     {
//         if (current->index < (int)half_stack)
//         {
//             if(current->chk == 0)
//                 current->nmbr_of_instr = current->index;
//         }
//         else
//         {
//             if (current->chk == 0)
//                 current->nmbr_of_instr = (int)ft_stacksize(*stack_a) - current->index;
//         }
//         current = current->next;
//     }
// }

// void ft_push_b(stack_node **stack_a,stack_node **stack_b)
// {
//     stack_node *current;
//     current = (*stack_a);

//     size_t half_stack;
//     half_stack = ft_stacksize(*stack_a) / 2;

//     *stack_b = NULL;

//     while (current->index < (int)half_stack)
//     {
//         half_stack = ft_stacksize(*stack_a) / 2;
//         if (current->chk == 0)
//         {
//             if (current->nmbr_of_instr == 0)
//                 ft_pb(stack_a,stack_b);
//             else
//             {
//                 int i;
//                 i = 0;
//                 while (i++ < current->nmbr_of_instr)
//                 {
//                     ft_ra(stack_a);
//                 }
//                 ft_pb(stack_a,stack_b);
//                 continue ;
//             }
//         }
//         current = current->next;
//     }
// }
/*--------------------------------------LIS------------------------------------------*/
/*--------------------------------------main------------------------------------------*/
int main(int ac, char **av)
{
    t_stack     stack_a;
    t_stack     stack_b;
    int         i;


    stack_a.size = 0;
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
            // if (ac == 1)
            //     stack_a.head = node_a;
            // else if (i + 1 == ac)
            //     stack_a.tail = node_a;
           
        }
        ft_push(&stack_b,4);
        ft_push(&stack_b,5);
        ft_push(&stack_b,6);
        // ft_min_data(&stack_a);
        // ft_index_lenght(stack_a);
        // ft_LIS(stack_a);
        // ft_instructions_number(&stack_a);
        // ft_push_b(&stack_a,&stack_b);
        // ft_rra(&stack_a);
        ft_pa(&stack_a,&stack_b);
        ft_printlist(stack_a.head);
        // ft_printlist(stack_b);
    }
    else
        ft_handle_error("INVALID ARGUMENT");
    return(0);
}
/*--------------------------------------main------------------------------------------*/