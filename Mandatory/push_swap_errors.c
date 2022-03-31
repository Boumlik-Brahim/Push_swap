/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:20:18 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/29 21:01:22 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle_error(char *str)
{
	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
	ft_putstr_fd(str, 1);
	exit(0);
}

void	ft_check_dup(t_stack *stack_a)
{
	t_stack_node	*current;
	t_stack_node	*nxt;

	current = stack_a->head;
	while (current)
	{
		nxt = current->next;
		while (nxt)
		{
			if (current->data == nxt->data)
			{
				ft_free_stack_a(stack_a);
				ft_handle_error("DUPLICATE NUMBERS\n");
			}
			else
				nxt = nxt->next;
		}
		current = current->next;
	}
}

void	ft_empty_arg(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = ft_strtrim(av[i], " ");
		if (ft_strlen(str) == 0)
			ft_handle_error("EMPTY ARGUMENTS");
		free(str);
		i++;
	}
}

void	ft_check_integers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '+' || str[i][j] == '-')
			j++;
		if (str[i][j] == '\0')
			ft_handle_error("SOME ARGS AREN'T INTEGERS\n");
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				ft_handle_error("SOME ARGS AREN'T INTEGERS\n");
			j++;
		}
		i++;
	}
}

void	ft_is_sorted(t_stack *stack_a)
{
	t_stack_node	*current;

	current = stack_a->head;
	while (current->next)
	{
		if (current->next->data > current->data)
			current = current->next;
		else
			return ;
	}
	exit(0);
}
