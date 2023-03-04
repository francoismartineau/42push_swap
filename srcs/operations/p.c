/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:12:01 by francoma          #+#    #+#             */
/*   Updated: 2023/02/23 12:19:31 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

// push from b to a
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	ft_printf("pa\n");
	tmp = pop_stack(b);
	push_stack(a, tmp);
}

// push from a to b
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	ft_printf("pb\n");
	tmp = pop_stack(a);
	push_stack(b, tmp);
}
