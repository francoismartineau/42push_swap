/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:37:40 by francoma          #+#    #+#             */
/*   Updated: 2023/02/20 15:38:53 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

# define ERROR -1
# define SUCCESS 0
# define DELIMITER ' '

typedef void	(*t_push_swap_func) (t_stack **, t_stack **);

typedef struct s_range_data
{
	int	mid;
	int	nth;
	int	size;
}	t_range_data;

int			in_range(int val, t_range_data range_data);
int			val_in_range_qty(t_stack *s, t_range_data range_data);
int			top_smaller_than_prev_prev(t_stack *s);
int			diff_top_prev_prev(t_stack *s);
int			diff_top_last(t_stack *s);

#endif