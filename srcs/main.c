/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:35:33 by francoma          #+#    #+#             */
/*   Updated: 2023/02/22 14:37:13 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runtime.h"	// exit_error
#include "init.h"		// parse_args
#include "sort.h"		// sort
#include "stack.h"		// free_stack

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (!*argv[1])
			return (0);
		stack = parse_arg(argv[1]);
	}
	else
		stack = parse_args(argv + 1, argc - 1);
	if (!stack)
		exit_error();
	sort(stack);
	return (0);
}
