/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:40:29 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/18 15:54:51 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(int *array)
{
	if (array)
	{
		free(array);
		array = NULL;
	}
}

void	printf_and_exit(char *message, t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			free_array(stacks->stack_a);
		if (stacks->stack_b)
			free_array(stacks->stack_b);
		if (stacks->index_stack)
			free_array(stacks->index_stack);
	}
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	check_doubles(t_stacks *stacks)
{
	int	count;
	int	count2;

	count = 0;
	while (count < stacks->size_a)
	{
		count2 = count + 1;
		while (count2 < stacks->size_a)
		{
			if (stacks->stack_a[count] == stacks->stack_a[count2])
				printf_and_exit("Duplicate number", stacks);
			count2++;
		}
		count++;
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			free_array(stacks->stack_a);
		if (stacks->stack_b)
			free_array(stacks->stack_b);
		if (stacks->index_stack)
			free_array(stacks->index_stack);
	}
}

void	printf_exit_and_str(char *message, t_stacks *stacks, char *arg_str)
{
	if (arg_str)
		free(arg_str);
	if (stacks)
	{
		if (stacks->stack_a)
			free_array(stacks->stack_a);
		if (stacks->stack_b)
			free_array(stacks->stack_b);
		if (stacks->index_stack)
			free_array(stacks->index_stack);
	}
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}
