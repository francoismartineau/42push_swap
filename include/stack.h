/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:23:41 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 15:49:10 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int				val;
	struct s_stack	*upper;
	struct s_stack	*prev;
}	t_stack;

t_stack	*encapsulate_val(int val);
t_stack	*pop_stack(t_stack **stack);
void	push_stack(t_stack **stack, t_stack	*new);
t_stack	*array_to_stack(int *numbers, int len);
t_stack	*free_stack(t_stack **stack);

void	swap_top(t_stack **stack);
void	make_first_last(t_stack **stack);
void	make_last_first(t_stack **stack);
t_stack	*get_last(t_stack *stack);
t_stack	*get_pre_last(t_stack *stack);

int		stack_min(t_stack *s);
int		stack_max(t_stack *s);
int		stack_val_pos(t_stack *s, int val);
int		stack_min_pos(t_stack *s);
int		stack_max_pos(t_stack *s);
int		stack_size(t_stack *s);
int		is_sorted(t_stack *s);

#endif