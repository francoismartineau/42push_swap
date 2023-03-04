/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:34:50 by francoma          #+#    #+#             */
/*   Updated: 2023/02/20 18:26:44 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc
#include "push_swap.h"	// t_stack
#include "stack.h"		// encapsulate_val, push_stack, free_stack
#include "libft.h"		// ft_atoi, ft_strlen, ft_isdigit
#include "init.h"		// normalize_stack

static int	ft_isnum(char *str)
{
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_is_int(char *str)
{
	int		len;
	int		i;
	int		is_positive;
	char	*int_max;

	if (!ft_isnum(str))
		return (0);
	is_positive = str[0] != '-';
	len = ft_strlen(str);
	if (len > 11 || (is_positive && len > 10))
		return (0);
	if ((len < 11 && !is_positive) || len < 10)
		return (1);
	int_max = "2147483647";
	str += !is_positive;
	i = 0;
	while (str[i])
	{
		if (str[i] > int_max[i] + (i == 9 && !is_positive))
			return (0);
		if (str[i] < int_max[i] + (i == 9 && !is_positive))
			return (1);
		i++;
	}
	return (1);
}

static int	ft_in_stack(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->val == val)
			return (1);
		stack = stack->prev;
	}
	return (0);
}

// Converts program arguments to a doubly chained list of ints
// Fails if:
// 	two identical values
//	non numerical value
//	value can't be contained in int
t_stack	*parse_args(char *argv[], int n)
{
	t_stack	*stack;
	t_stack	*curr;
	int		i;

	stack = NULL;
	i = n;
	while (i > 0)
	{
		curr = encapsulate_val(ft_atoi(argv[i - 1]));
		if (!curr || !ft_is_int(argv[i - 1])
			|| ft_in_stack(stack, curr->val))
		{
			free(curr);
			free_stack(&stack);
			return (NULL);
		}
		push_stack(&stack, curr);
		i--;
	}
	normalize_stack(&stack);
	return (stack);
}
