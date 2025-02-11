/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:13:27 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/11 12:47:35 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stacks *stacks)
{
	int count;

	if(stacks->size_b > 0)
	{
		count = stacks->size_a;
		while(count > 0)
		{
			stacks->stack_a[count] = stacks->stack_a[count - 1];
			count--;
		}
		stacks->stack_a[0] = stacks->stack_b[0];
		stacks->size_a++;
		count = 0;
		while (count < stacks->size_b - 1)
		{
			stacks->stack_b[count] = stacks->stack_b[count + 1];
			count++;
		}
		stacks->size_b--;
		ft_printf("pa\n");
	}
}

void pb(t_stacks *stacks)
{
	int count;

	if(stacks->size_a > 0)
	{
		count = stacks->size_b;
		while(count > 0)
		{
			stacks->stack_b[count] = stacks->stack_b[count - 1];
			count--;
		}

		stacks->stack_b[0] = stacks->stack_a[0];
		stacks->size_b++;

		count = 0;
		while (count < stacks->size_a - 1)
		{
			stacks->stack_a[count] = stacks->stack_a[count + 1];
			count++;
		}
		stacks->size_a--;
		ft_printf("pb\n");
	}
}
