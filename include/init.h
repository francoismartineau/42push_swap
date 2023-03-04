/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:20:50 by francoma          #+#    #+#             */
/*   Updated: 2023/02/20 18:45:50 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "push_swap.h"

t_stack	*parse_arg(char *arg);
t_stack	*parse_args(char *argv[], int n);
void	normalize_stack(t_stack **s);

int		prev_is_minus(int i, char *arg);
int		skip_delimiters(int i, char *arg);
int		skip_digits(int i, char *arg);
int		has_bad_char(char *arg);

#endif