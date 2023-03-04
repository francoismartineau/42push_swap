/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:22:00 by francoma          #+#    #+#             */
/*   Updated: 2023/02/14 16:45:44 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <limits.h>

int	stack_min(t_stack *s)
{
	int	min;

	min = INT_MAX;
	while (s)
	{
		if (s->val < min)
			min = s->val;
		s = s->prev;
	}
	return (min);
}

int	stack_max(t_stack *s)
{
	int	max;

	max = INT_MIN;
	while (s)
	{
		if (s->val > max)
			max = s->val;
		s = s->prev;
	}
	return (max);
}

int	stack_val_pos(t_stack *s, int val)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->val == val)
			return (i);
		i++;
		s = s->prev;
	}
	return (-1);
}

int	stack_max_pos(t_stack *s)
{
	return (stack_val_pos(s, stack_max(s)));
}

int	stack_min_pos(t_stack *s)
{
	return (stack_val_pos(s, stack_min(s)));
}
