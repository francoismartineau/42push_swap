/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:16:54 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 10:57:07 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "debug.h"

// make last first a
void	rra_bonus(t_stack **a, t_stack **b)
{
	(void) b;
	make_last_first(a);
}

// make last first b
void	rrb_bonus(t_stack **a, t_stack **b)
{
	(void) a;
	make_last_first(b);
}

// make last first a, b
void	rrr_bonus(t_stack **a, t_stack **b)
{
	make_last_first(a);
	make_last_first(b);
}
