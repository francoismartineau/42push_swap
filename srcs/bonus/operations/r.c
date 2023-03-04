/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:14:44 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 10:57:07 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "debug.h"

// make first last a
void	ra_bonus(t_stack **a, t_stack **b)
{
	(void) b;
	make_first_last(a);
}

// make first last b
void	rb_bonus(t_stack **a, t_stack **b)
{
	(void) a;
	make_first_last(b);
}

// make first last a, b
void	rr_bonus(t_stack **a, t_stack **b)
{
	make_first_last(a);
	make_first_last(b);
}
