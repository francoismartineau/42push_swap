/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:12:01 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 10:57:40 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "debug.h"

// push from b to a
void	pa_bonus(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = pop_stack(b);
	push_stack(a, tmp);
}

// push from a to b
void	pb_bonus(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = pop_stack(a);
	push_stack(b, tmp);
}
