/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:27:13 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/21 14:49:48 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_stack_a_split(char *stack_a)
{
	char	**stack_a_split;

	stack_a_split = ft_split(stack_a, ' ');
	if (!stack_a_split)
		printf_exit_and_str("stack_a no no split", NULL, stack_a);
	return (stack_a_split);
}

int	*create_stack(char **stack_a_split)
{
	int		*stack_a_int;
	int		stack_a_lenght;
	int		count;
	long	num;

	count = 0;
	stack_a_lenght = ft_strlen_index(stack_a_split);
	stack_a_int = ft_calloc(stack_a_lenght, sizeof(int));
	if (!stack_a_int)
		printf_and_exit("stack_a_int no no malloc", NULL);
	while (count < stack_a_lenght)
	{
		num = ft_atolo(stack_a_split[count]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_split(stack_a_split);
			free_array(stack_a_int);
			printf_and_exit("Number out of int range", NULL);
		}
		stack_a_int[count] = (int)num;
		count++;
	}
	return (stack_a_int);
}

char	*create_argument_str(char *argv[])
{
	int		count;
	char	*temp;
	char	*arg_str;

	count = 1;
	temp = ft_strdup("");
	if (!temp)
		printf_and_exit("temp string failed", NULL);
	while (argv[count] != NULL)
	{
		arg_str = ft_strjoin(temp, " ");
		free(temp);
		temp = ft_strjoin(arg_str, argv[count]);
		free(arg_str);
		arg_str = temp;
		count++;
	}
	temp = NULL;
	return (arg_str);
}

void	create_stacks(char *arg_str, t_stacks *stacks)
{
	char	**stack_a_split;

	check_argument(arg_str);
	stack_a_split = create_stack_a_split(arg_str);
	if (!stack_a_split)
		printf_exit_and_str("stack_a_split no no malloc", NULL, arg_str);
	free(arg_str);
	stacks->stack_a = create_stack(stack_a_split);
	if (!stacks->stack_a)
		printf_and_exit("stack_a no no malloc", stacks);
	stacks->size_a = ft_strlen_index(stack_a_split);
	stacks->index_stack = create_stack(stack_a_split);
	if (!stacks->index_stack)
		printf_and_exit("index_stack no no malloc", stacks);
	free_split(stack_a_split);
	check_doubles(stacks);
}

void	prepair_stacks(char *arg_str, t_stacks *stacks)
{
	create_stacks(arg_str, stacks);
	stacks->stack_b = ft_calloc(stacks->size_a, sizeof(int));
	if (!stacks->stack_b)
		printf_and_exit("Memory allocation failed for stack_b", stacks);
	stacks->size_b = 0;
	stacks->index_stack = bubble_sort_stack(stacks->index_stack,
			stacks->size_a);
	stacks->size_i = stacks->size_a;
}
