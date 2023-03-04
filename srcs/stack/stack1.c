/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:43:58 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 17:19:35 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc, free
#include "push_swap.h"

void	push_stack(t_stack **stack, t_stack	*new)
{
	if (!new)
		return ;
	if (*stack)
		(*stack)->upper = new;
	new->prev = *stack;
	new->upper = NULL;
	*stack = new;
}

t_stack	*pop_stack(t_stack **stack)
{
	t_stack	*res;

	res = *stack;
	if (!res)
		return (NULL);
	res->upper = NULL;
	*stack = (*stack)->prev;
	return (res);
}

t_stack	*encapsulate_val(int val)
{
	t_stack	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->val = val;
	res->upper = NULL;
	res->prev = NULL;
	return (res);
}

t_stack	*free_stack(t_stack **stack)
{
	t_stack	*prev;

	if (!stack)
		return (NULL);
	while (*stack)
	{
		prev = (*stack)->prev;
		free(*stack);
		*stack = prev;
	}
	*stack = NULL;
	return (*stack);
}
