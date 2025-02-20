/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:13:27 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/20 09:43:48 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	int	count;

	if (stacks->size_b > 0)
	{
		count = stacks->size_a - 1;
		while (count >= 0)
		{
			stacks->stack_a[count + 1] = stacks->stack_a[count];
			count--;
		}
		stacks->stack_a[0] = stacks->stack_b[0];
		stacks->size_a += 1;
		count = 0;
		stacks->size_b -= 1;
		while (count < stacks->size_b)
		{
			stacks->stack_b[count] = stacks->stack_b[count + 1];
			count++;
		}
		write(1, "pa\n", 3);
	}
}

void	pb(t_stacks *stacks)
{
	int	count;

	if (stacks->size_a > 0)
	{
		count = stacks->size_b - 1;
		while (count >= 0)
		{
			stacks->stack_b[count + 1] = stacks->stack_b[count];
			count--;
		}
		stacks->stack_b[0] = stacks->stack_a[0];
		stacks->size_b += 1;
		count = 0;
		stacks->size_a -= 1;
		while (count < stacks->size_a)
		{
			stacks->stack_a[count] = stacks->stack_a[count + 1];
			count++;
		}
		write(1, "pb\n", 3);
	}
}
