/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:40:29 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/14 18:18:55 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_and_exit(char *message)
{
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
				printf_and_exit("Duplicate number");
			count2++;
		}
		count++;
	}
}
