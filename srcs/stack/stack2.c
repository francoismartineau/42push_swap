/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:08:08 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 12:09:27 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack **stack)
{
	int	tmp;

	if (!*stack || !(*stack)->prev)
		return ;
	tmp = (*stack)->val;
	(*stack)->val = (*stack)->prev->val;
	(*stack)->upper = NULL;
	(*stack)->prev->upper = (*stack);
	(*stack)->prev->val = tmp;
}

t_stack	*get_last(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

void	make_first_last(t_stack **stack)
{
	t_stack	*pre_last;

	if (!stack || !*stack)
		return ;
	pre_last = get_last(*stack);
	pre_last->prev = *stack;
	*stack = (*stack)->prev;
	pre_last->prev->upper = pre_last;
	pre_last->prev->prev = NULL;
}

t_stack	*get_pre_last(t_stack *stack)
{
	if (!stack || !stack->prev)
		return (NULL);
	while (stack->prev->prev)
		stack = stack->prev;
	return (stack);
}

void	make_last_first(t_stack **stack)
{
	t_stack	*pre_last;
	t_stack	*temp_last;

	pre_last = get_pre_last(*stack);
	if (!pre_last)
		return ;
	temp_last = pre_last->prev;
	pre_last->prev = NULL;
	temp_last->prev = *stack;
	(*stack)->upper = temp_last;
	*stack = temp_last;
	temp_last->upper = NULL;
}
