/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:44:50 by bbrahim           #+#    #+#             */
/*   Updated: 2022/03/30 21:44:09 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

void	ft_check_inst(char *instructions, t_stack_b *stack_a,
		t_stack_b *stack_b)
{
	if (ft_strcmp(instructions, "sa\n") == 0)
		ft_sa_b(stack_a);
	else if (ft_strcmp(instructions, "sb\n") == 0)
		ft_sb_b(stack_b);
	else if (ft_strcmp(instructions, "ss\n") == 0)
		ft_ss_b(stack_a, stack_b);
	else if (ft_strcmp(instructions, "pa\n") == 0)
		ft_pa_b(stack_a, stack_b);
	else if (ft_strcmp(instructions, "pb\n") == 0)
		ft_pb_b(stack_a, stack_b);
	else if (ft_strcmp(instructions, "ra\n") == 0)
		ft_ra_b(stack_a);
	else if (ft_strcmp(instructions, "rb\n") == 0)
		ft_rb_b(stack_b);
	else if (ft_strcmp(instructions, "rr\n") == 0)
		ft_rr_b(stack_a, stack_b);
	else if (ft_strcmp(instructions, "rra\n") == 0)
		ft_rra_b(stack_a);
	else if (ft_strcmp(instructions, "rrb\n") == 0)
		ft_rrb_b(stack_b);
	else if (ft_strcmp(instructions, "rrr\n") == 0)
		ft_rrr_b(stack_a, stack_b);
	else
		ft_handle_error("Invalid Instruction\n");
}

int	ft_check_is_sorted(t_stack_b *stack_a)
{
	t_stack_node_b	*current;

	current = stack_a->head;
	while (current->next)
	{
		if (current->next->data > current->data)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	ft_get_inst(t_stack_b *stack_a, t_stack_b *stack_b)
{
	int		i;
	char	*inst;

	i = 0;
	inst = get_next_line(0);
	while (inst != NULL)
	{
		ft_check_inst(inst, stack_a, stack_b);
		free (inst);
		inst = get_next_line(0);
	}
	if (ft_check_is_sorted(stack_a) == 1 && stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack_b	stack_a;
	t_stack_b	stack_b;
	char		**data;
	int			i;
	int			a;

	i = 0;
	if (ac == 1)
		return (0);
	data = ft_join_args(i, ac, av);
	i = 0;
	while (data[i])
		i++;
	while (i > 0)
	{
		a = ft_atoi(data[--i]);
		ft_push_b(&stack_a, a);
	}
	ft_check_dup_b(&stack_a);
	ft_get_inst(&stack_a, &stack_b);
	return (0);
}
