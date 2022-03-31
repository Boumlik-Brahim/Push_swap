/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:46:46 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:45:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_handle_error(char *str)
{
	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
	ft_putstr_fd(str, 1);
	exit(0);
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

void	ft_check_dup_b(t_stack_b *stack_a)
{
	t_stack_node_b	*current;
	t_stack_node_b	*nxt;

	current = stack_a->head;
	while (current)
	{
		nxt = current->next;
		while (nxt)
		{
			if (current->data == nxt->data)
			{
				ft_free_stack_a_b(stack_a);
				ft_handle_error("DUPLICATE NUMBERS\n");
			}
			else
				nxt = nxt->next;
		}
		current = current->next;
	}
}
