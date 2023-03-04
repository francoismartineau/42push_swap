/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:40:21 by francoma          #+#    #+#             */
/*   Updated: 2023/02/10 14:23:16 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "push_swap.h"

void	test_procedure(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);
void	print_stack_vals(t_stack *s);

#endif