/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranges_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:27:12 by francoma          #+#    #+#             */
/*   Updated: 2023/02/20 15:38:49 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(int val, t_range_data range_data)
{
	int	m;
	int	s;
	int	nth;

	m = range_data.mid;
	s = range_data.size / 2;
	nth = range_data.nth;
	return ((val >= (m + s * nth) && val <= (m + s * (nth + 1)))
		|| (val <= (m - s * nth) && val >= (m - s * (nth + 1))));
}

int	val_in_range_qty(t_stack *s, t_range_data range_data)
{
	int	num;

	num = 0;
	while (s)
	{
		if (in_range(s->val, range_data))
			num++;
		s = s->prev;
	}
	return (num);
}

int	top_smaller_than_prev_prev(t_stack *s)
{
	return (s->val < s->prev->prev->val);
}

int	diff_top_prev_prev(t_stack *s)
{
	return (ft_abs(s->val - s->prev->prev->val));
}

int	diff_top_last(t_stack *s)
{
	return (ft_abs(s->val - get_last(s)->val));
}
