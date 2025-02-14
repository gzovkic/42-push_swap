/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:24:44 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/14 18:18:43 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char		*arg_str;
	t_stacks	stacks;

	stacks.size_b = 0;
	if (argc == 2)
	{
		sort_stack_a(argv[1], &stacks);
		k_sort(&stacks);
	}
	else if (argc > 2)
	{
		arg_str = create_argument_str(argv);
		sort_stack_a(arg_str, &stacks);
		k_sort(&stacks);
	}
	else
		printf_and_exit("Wrong amount of arguments");
	return (0);
}
