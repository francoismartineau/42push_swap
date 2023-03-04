/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:43:44 by francoma          #+#    #+#             */
/*   Updated: 2023/03/04 13:47:00 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "bonus.h"
#include "debug.h"
#include <stdlib.h>

static int	is_str(char *s1, char *s2)
{
	return (0 == ft_strcmp(s1, s2));
}

static t_push_swap_func	get_operation(char *line)
{
	if (is_str(line, "sa\n"))
		return (sa_bonus);
	if (is_str(line, "sb\n"))
		return (sb_bonus);
	if (is_str(line, "ss\n"))
		return (ss_bonus);
	if (is_str(line, "ra\n"))
		return (ra_bonus);
	if (is_str(line, "rb\n"))
		return (rb_bonus);
	if (is_str(line, "rr\n"))
		return (rr_bonus);
	if (is_str(line, "rra\n"))
		return (rra_bonus);
	if (is_str(line, "rrb\n"))
		return (rrb_bonus);
	if (is_str(line, "rrr\n"))
		return (rrr_bonus);
	if (is_str(line, "pa\n"))
		return (pa_bonus);
	if (is_str(line, "pb\n"))
		return (pb_bonus);
	return (ERROR_OPERATION);
}

void	apply_operations(t_stack *a)
{
	char				*line;
	t_stack				*b;
	t_push_swap_func	operation;

	b = NULL;
	operation = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		operation = get_operation(line);
		free(line);
		if (!operation || operation == ERROR_OPERATION)
			break ;
		operation(&a, &b);
	}
	if (operation == ERROR_OPERATION)
		ft_putstr_fd("Error.\n", 2);
	else if (!b && is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
}
