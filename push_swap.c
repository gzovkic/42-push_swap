/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:24:44 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/16 16:33:41 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	printf("\n");
	system("leaks push_swap");
}
void free_stacks(t_stacks *stacks)
{
	if(stacks)
	{
	if (stacks->stack_a)
		free_array(stacks->stack_a);
	if (stacks->stack_b)
		free_array(stacks->stack_b);
	if (stacks->index_stack)
		free_array(stacks->index_stack);
	}
}

int	main(int argc, char *argv[])
{
	char		*arg_str;
	t_stacks	stacks;

	// atexit(leaks);


	stacks.size_b = 0;
	if (argc == 2)
	{
		prepair_stacks(argv[1], &stacks);
		k_sort(&stacks);
		free_stacks(&stacks);
	}
	else if (argc > 2)
	{
		arg_str = create_argument_str(argv);
		prepair_stacks(arg_str, &stacks);
		free(arg_str);
		k_sort(&stacks);
		free_stacks(&stacks);
	}
	else
		printf_and_exit("Wrong amount of arguments", NULL);
	return (0);
}
