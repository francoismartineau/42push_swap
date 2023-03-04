/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:14:44 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:22:12 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

// make first last a
void	ra(t_stack **a, t_stack **b)
{
	ft_printf("ra\n");
	(void) b;
	make_first_last(a);
}

// make first last b
void	rb(t_stack **a, t_stack **b)
{
	ft_printf("rb\n");
	(void) a;
	make_first_last(b);
}

// make first last a, b
void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	make_first_last(a);
	make_first_last(b);
}
