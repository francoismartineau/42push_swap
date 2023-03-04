/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:34:50 by francoma          #+#    #+#             */
/*   Updated: 2023/02/22 15:01:09 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc
#include "push_swap.h"	// t_stack
#include "stack.h"		// encapsulate_val, push_stack, free_stack
#include "libft.h"		// ft_atoi, ft_strlen, ft_isdigit
#include "init.h"		// normalize_stack

static size_t	ft_strlen_delimiter(const char *s, const char delimiter)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] && s[len] != delimiter)
		len++;
	return (len);
}

static int	ft_isnum(char *str, char delimiter)
{
	if (*str == '-')
		str++;
	if (!*str || *str == delimiter)
		return (0);
	while (*str && *str != delimiter)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_is_int(char *str, char delimiter)
{
	int		len;
	int		i;
	int		is_positive;
	char	*int_max;

	if (!ft_isnum(str, delimiter))
		return (0);
	is_positive = str[0] != '-';
	len = ft_strlen_delimiter(str, delimiter);
	if (len > 11 || (is_positive && len > 10))
		return (0);
	if ((len < 11 && !is_positive) || len < 10)
		return (1);
	int_max = "2147483647";
	str += !is_positive;
	i = 0;
	while (str[i] && str[i] != delimiter)
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
t_stack	*parse_arg(char *arg)
{
	t_stack	*stack;
	t_stack	*curr;
	int		i;

	if (has_bad_char(arg))
		return (NULL);
	stack = NULL;
	i = ft_strlen(arg);
	while (i > 0)
	{
		i = skip_delimiters(i, arg);
		i = skip_digits(i, arg);
		i -= prev_is_minus(i, arg);
		curr = encapsulate_val(ft_atoi(arg + i));
		if (!curr || !ft_is_int(arg + i, DELIMITER)
			|| ft_in_stack(stack, curr->val))
		{
			free(curr);
			return (free_stack(&stack));
		}
		push_stack(&stack, curr);
		i--;
	}
	normalize_stack(&stack);
	return (stack);
}
