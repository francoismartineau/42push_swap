/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:38:10 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 11:40:53 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <limits.h>

int	stack_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->prev;
	}
	return (i);
}

int	is_sorted(t_stack *s)
{
	while (s)
	{
		if (s->prev && s->val > s->prev->val)
			return (0);
		s = s->prev;
	}
	return (1);
}
