/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:59:12 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 10:57:07 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "debug.h"

// swap top two of stack a
void	sa_bonus(t_stack **a, t_stack **b)
{
	(void) b;
	swap_top(a);
}

// swap top two of stack b
void	sb_bonus(t_stack **a, t_stack **b)
{
	(void) a;
	swap_top(b);
}

// swap top two of both stacks
void	ss_bonus(t_stack **a, t_stack **b)
{
	swap_top(a);
	swap_top(b);
}
