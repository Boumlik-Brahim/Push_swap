/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:45:12 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:50:56 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_init_node_b(t_stack_node_b *node, int data)
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

void	ft_push_b(t_stack_b *stack, int data)
{
	t_stack_node_b	*new_node;

	new_node = (t_stack_node_b *)malloc(sizeof(t_stack_node_b));
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
	ft_init_node_b(new_node, data);
	stack->head->prev = NULL;
	stack->size += 1;
}

void	ft_free_stack_a_b(t_stack_b *stack_a)
{
	t_stack_node_b	*root;
	t_stack_node_b	*ptr;

	root = NULL;
	ptr = stack_a->head;
	if (!stack_a->head)
		stack_a->head = NULL;
	while (ptr != NULL)
	{
		root = ptr;
		ptr = ptr->next;
		free(root);
	}
	stack_a->head = NULL;
}
