/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:24:44 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/06 12:38:38 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(char *arg_str, t_stacks *stacks)
{
	char	**stack_a_split;
	int stack_a_lenght;

	check_argument(arg_str);
	stack_a_split = create_stack_a_split(arg_str);
	stacks->stack_a = create_stack_a_int(stack_a_split);
	stack_a_lenght = ft_strlen_index(stack_a_split);
	int count = 0;
	while(count < stack_a_lenght)
	{
		ft_printf("%d\n", stacks->stack_a[count]);
		count++;
	}
	stacks->index_stack = bubble_sort_stack(stacks->stack_a, stack_a_lenght);
	count = 0;
	ft_printf("\nSorted: \n");
	while(count < stack_a_lenght)
	{
		ft_printf("%d\n", stacks->index_stack[count]);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	char *arg_str;
	t_stacks stacks;
	
	if (argc == 2)
		sort_stack_a(argv[1], &stacks);
	else if(argc > 2)
	{
		arg_str = create_argument_str(argv);
		sort_stack_a(arg_str, &stacks);
	}
	else
		printf_and_exit("Wrong amount of arguments");
	return (0);
}
