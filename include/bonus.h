/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:58:48 by francoma          #+#    #+#             */
/*   Updated: 2023/02/25 15:33:11 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "stack.h"

# define ERROR_OPERATION (void *) -1

void	apply_operations(t_stack *a);

void	sa_bonus(t_stack **a, t_stack **b);
void	sb_bonus(t_stack **a, t_stack **b);
void	ss_bonus(t_stack **a, t_stack **b);

void	pa_bonus(t_stack **a, t_stack **b);
void	pb_bonus(t_stack **a, t_stack **b);

void	ra_bonus(t_stack **a, t_stack **b);
void	rb_bonus(t_stack **a, t_stack **b);
void	rr_bonus(t_stack **a, t_stack **b);

void	rra_bonus(t_stack **a, t_stack **b);
void	rrb_bonus(t_stack **a, t_stack **b);
void	rrr_bonus(t_stack **a, t_stack **b);

#endif