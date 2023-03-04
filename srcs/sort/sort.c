/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:56:54 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:15:12 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	sort(t_stack *a)
{
	int		size;

	if (is_sorted(a))
	{
		free_stack(&a);
		return ;
	}
	size = stack_size(a);
	if (size < 9)
		sort_few(a, NULL);
	else if (size < 15)
		sort_to_b(a, NULL);
	else
		sort_ranges(a, NULL);
}
