/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:47:33 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 22:23:27 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_node(t_stack_node *node, int data)
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

char	**ft_join_args(int i, int ac, char **av)
{
	char	*res;
	char	**str;
	char	*ptr;
	char	*s;

	ft_empty_arg(ac, av);
	res = ft_strdup("");
	while (av[++i])
	{
		if (av[i][0] == '\0')
			ft_handle_error("SOME ARGS AREN'T INTEGERS\n");
		s = ft_strjoin(av[i], " ");
		ptr = res;
		res = ft_strjoin(res, s);
		free(ptr);
		free(s);
	}
	str = ft_split(res, ' ');
	free(res);
	ft_check_integers(str);
	return (str);
}

void	ft_push(t_stack *stack, int data)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
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
	ft_init_node(new_node, data);
	stack->head->prev = NULL;
	stack->size += 1;
}

void	ft_index(t_stack *stack_a)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = stack_a->head;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	ft_instructions_number(t_stack *stack_a)
{
	t_stack_node	*current;

	ft_index(stack_a);
	current = stack_a->head;
	while (current)
	{
		if (stack_a->size == 1)
			current->nmbr_of_instr = 0;
		else if (current->index <= (stack_a->size / 2))
			current->nmbr_of_instr = current->index;
		else
			current->nmbr_of_instr = (stack_a->size - current->index) * -1;
		current = current->next;
	}
}
