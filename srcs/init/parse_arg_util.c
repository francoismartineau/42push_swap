/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:33:02 by francoma          #+#    #+#             */
/*   Updated: 2023/02/20 18:49:46 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	skip_delimiters(int i, char *arg)
{
	while (i > 0 && arg[i - 1] == DELIMITER)
		i--;
	return (i);
}

int	skip_digits(int i, char *arg)
{
	while (i > 0 && ft_isdigit(arg[i - 1]))
		i--;
	return (i);
}

int	prev_is_minus(int i, char *arg)
{
	return (i > 0 && arg[i - 1] == '-');
}

int	has_bad_char(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != DELIMITER && arg[i] != '-' && !ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}
