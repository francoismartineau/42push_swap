/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranges.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:37:52 by francoma          #+#    #+#             */
/*   Updated: 2023/02/22 12:18:57 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include "stack.h"

static t_range_data	init_range_data(t_stack *a)
{
	t_range_data	data;

	data.mid = stack_max(a) / 2;
	data.nth = 0;
	data.size = stack_size(a) * 3 / 40 + 22;
	return (data);
}

static void	rotate_b(t_stack **a, t_stack **b, t_range_data range_data)
{
	if (*a && !in_range((*a)->val, range_data)
		&& val_in_range_qty(*a, range_data))
		rr(a, b);
	else
		rb(a, b);
}

static void	handle_range_val(t_stack **a, t_stack **b, t_range_data range_data)
{
	pb(a, b);
	if (stack_size(*b) == 1 || (*b)->val > (*b)->prev->val)
		return ;
	if (stack_size(*b) == 2 || (top_smaller_than_prev_prev(*b)
			&& diff_top_prev_prev(*b) >= diff_top_last(*b)))
		rotate_b(a, b, range_data);
}

static void	sort_to_a(t_stack **a, t_stack **b)
{
	int	sec_max_pushed;

	sec_max_pushed = 0;
	while (*b)
	{
		if (stack_max_pos(*b) == 0)
		{
			pa(a, b);
			if (sec_max_pushed)
			{
				sa(a, b);
				sec_max_pushed = 0;
			}
		}
		else if (stack_val_pos(*b, stack_max(*b) - 1) == 0 && !sec_max_pushed)
		{
			pa(a, b);
			sec_max_pushed = 1;
		}
		else if (stack_max_pos(*b) <= stack_size(*b) / 2)
			rb(a, b);
		else
			rrb(a, b);
	}
}

void	sort_ranges(t_stack *a, t_stack *b)
{
	t_range_data	range_data;

	range_data = init_range_data(a);
	while (a)
	{
		while (val_in_range_qty(a, range_data))
		{
			if (in_range(a->val, range_data))
				handle_range_val(&a, &b, range_data);
			else
				ra(&a, &b);
		}
		range_data.nth++;
	}
	sort_to_a(&a, &b);
	free_stack(&a);
}
