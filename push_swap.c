/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:24:44 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/18 15:55:09 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	printf("\n");
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	char		*arg_str;
	t_stacks	stacks;

	atexit(leaks);
	if (argc == 2)
	{
		arg_str = ft_strdup(argv[1]);
		if (!arg_str)
			printf_and_exit("arg_str no no strdup", NULL);
		prepair_stacks(arg_str, &stacks);
		k_sort(&stacks);
		free_stacks(&stacks);
	}
	else if (argc > 2)
	{
		arg_str = create_argument_str(argv);
		prepair_stacks(arg_str, &stacks);
		k_sort(&stacks);
		free_stacks(&stacks);
	}
	else
		printf_and_exit("Wrong amount of arguments", NULL);
	return (0);
}
