/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:40:49 by francoma          #+#    #+#             */
/*   Updated: 2023/02/15 13:25:24 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

void	sort(t_stack *stack);

void	sort_few(t_stack *a, t_stack *b);
void	sort_to_b(t_stack *a, t_stack *b);
void	sort_ranges(t_stack *a, t_stack *b);

#endif