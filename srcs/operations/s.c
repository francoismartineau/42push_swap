/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:59:12 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:22:17 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

// swap top two of stack a
void	sa(t_stack **a, t_stack **b)
{
	ft_printf("sa\n");
	(void) b;
	swap_top(a);
}

// swap top two of stack b
void	sb(t_stack **a, t_stack **b)
{
	ft_printf("sb\n");
	(void) a;
	swap_top(b);
}

// swap top two of both stacks
void	ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap_top(a);
	swap_top(b);
}
