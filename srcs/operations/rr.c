/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:16:54 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:22:11 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

// make last first a
void	rra(t_stack **a, t_stack **b)
{
	ft_printf("rra\n");
	(void) b;
	make_last_first(a);
}

// make last first b
void	rrb(t_stack **a, t_stack **b)
{
	ft_printf("rrb\n");
	(void) a;
	make_last_first(b);
}

// make last first a, b
void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	make_last_first(a);
	make_last_first(b);
}
