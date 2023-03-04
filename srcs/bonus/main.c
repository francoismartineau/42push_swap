/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:14:32 by francoma          #+#    #+#             */
/*   Updated: 2023/02/20 14:49:04 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"				// parse_args
#include "runtime.h"			// exit_error
#include "bonus.h"				// apply_operations
#include "stack.h"				// free_stack

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	if (argc == 2)
		stack = parse_arg(argv[1]);
	else
		stack = parse_args(argv + 1, argc - 1);
	if (!stack)
		exit_error();
	apply_operations(stack);
	return (0);
}
