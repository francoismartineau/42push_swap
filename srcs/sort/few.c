/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:53:03 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:35:50 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

/* We always keep b in reverse order
Therefore we want to stack on b only if a's top is relatively small.
	If a's top is smaller than a's second and last value,
	but greater than b's top, we stack from a to b.
 	If we find an element that is smaller than b's top,
	we stack from b to a and keep going.
*/
void	sort_few(t_stack *a, t_stack *b)
{
	while (!is_sorted(a) || (b && b->val > a->val))
	{
		if (get_last(a)->val == 1 && a->val == 0)
		{
			rra(&a, &b);
			sa(&a, &b);
		}
		else if (stack_size(a) == 2)
			ra(&a, &b);
		else if (a->val < a->prev->val && a->val < get_last(a)->val
			&& (!b || a->val > b->val))
			pb(&a, &b);
		else if (get_last(a)->val < a->val && a->val < a->prev->val)
			rra(&a, &b);
		else if (a->prev->val < get_last(a)->val && get_last(a)->val < a->val)
			ra(&a, &b);
		else if ((a->prev->val < a->val && a->val < get_last(a)->val)
			|| (get_last(a)->val < a->prev->val && a->prev->val < a->val))
			sa(&a, &b);
		else
			pa(&a, &b);
	}
	while (b)
		pa(&a, &b);
	free_stack(&a);
}
