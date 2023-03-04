/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:53:03 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:26:36 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

void	sort_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (!is_sorted(a))
	{
		min_pos = stack_min_pos(a);
		if (min_pos == 0)
			pb(&a, &b);
		else if (min_pos == 1)
			sa(&a, &b);
		else if (min_pos <= stack_size(a) / 2)
			ra(&a, &b);
		else
			rra(&a, &b);
	}
	while (b)
		pa(&a, &b);
	free_stack(&a);
}
