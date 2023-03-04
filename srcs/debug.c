/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:26:27 by francoma          #+#    #+#             */
/*   Updated: 2023/02/14 16:34:53 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <stdlib.h>

#define MAX_PRINT 200

void	print_stack_vals(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		ft_printf("%i ", s->val);
		if (i % 15 == 14)
			ft_printf("\\\n");
		i++;
		s = s->prev;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while ((a || b) && i < MAX_PRINT)
	{
		if (a)
		{
			ft_printf("%38i", a->val);
			a = a->prev;
		}
		else
			ft_printf("%38c", ' ');
		ft_printf(" ");
		if (b)
		{
			ft_printf("%38i", b->val);
			b = b->prev;
		}
		else
			ft_printf("%38c", ' ');
		ft_printf("\n");
		i++;
	}
	ft_printf("%38c %38c\n%38c %38c\n\n", '-', '-', 'a', 'b');
	free(get_next_line(1));
}

static void	test_procedure_continuation(t_stack *a, t_stack *b, t_stack *tmp)
{
	tmp = pop_stack(&a);
	ft_printf("pop a: %i\n", tmp->val);
	print_stacks(a, b);
	ft_printf("push b: %i\n", tmp->val);
	push_stack(&b, tmp);
	print_stacks(a, b);
	free_stack(&a);
	free_stack(&b);
}

void	test_procedure(t_stack *a)
{
	t_stack	*b;
	t_stack	*tmp;

	b = NULL;
	print_stacks(a, b);
	ft_printf("swap top a\n");
	swap_top(&a);
	print_stacks(a, b);
	tmp = pop_stack(&a);
	ft_printf("pop a: %i\n", tmp->val);
	print_stacks(a, b);
	ft_printf("push a: %i\n", tmp->val);
	push_stack(&a, tmp);
	print_stacks(a, b);
	ft_printf("make_first_last a\n");
	make_first_last(&a);
	print_stacks(a, b);
	ft_printf("make_last_first a\n");
	make_last_first(&a);
	print_stacks(a, b);
	test_procedure_continuation(a, b, tmp);
}
