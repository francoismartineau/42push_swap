/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:49 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:19:19 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

static void	ft_swap(int	*a, int	*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	curr_min;
	int	curr_min_index;

	i = 0;
	while (i < size)
	{
		curr_min_index = i;
		curr_min = array[curr_min_index];
		j = i + 1;
		while (j < size)
		{
			if (array[j] < curr_min)
			{
				curr_min = array[j];
				curr_min_index = j;
			}
			j++;
		}
		if (curr_min_index != i)
			ft_swap(&array[i], &array[curr_min_index]);
		i++;
	}
}

static int	*stack_to_array(t_stack *s)
{
	int	*array;
	int	i;
	int	size;

	size = stack_size(s);
	array = malloc(sizeof(*array) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = s->val;
		s = s->prev;
		i++;
	}
	return (array);
}

static int	nth_in_array(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_stack **s)
{
	t_stack	*curr;
	int		*array;
	int		size;

	array = stack_to_array(*s);
	if (!array)
	{
		free_stack(s);
		return ;
	}
	size = stack_size(*s);
	sort_array(array, size);
	curr = *s;
	while (curr)
	{
		curr->val = nth_in_array(array, size, curr->val);
		curr = curr->prev;
	}
	free(array);
}
