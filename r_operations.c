/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/02/07 13:59:27 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/10 10:02:08 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_no_print(t_stacks *stacks)
{
	int	temp;
	int	count;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a[0];
		count = 0;
		while (count < stacks->size_a - 1)
		{
			stacks->stack_a[count] = stacks->stack_a[count + 1];
			count++;
		}
		stacks->stack_a[stacks->size_a - 1] = temp;
	}
}

void	rb_no_print(t_stacks *stacks)
{
	int	temp;
	int	count;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b[0];
		count = 0;
		while (count < stacks->size_b - 1)
		{
			stacks->stack_b[count] = stacks->stack_b[count + 1];
			count++;
		}
		stacks->stack_b[stacks->size_b - 1] = temp;
	}
}

void	ra(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		ra_no_print(stacks);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		rb_no_print(stacks);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stacks *stacks)
{
	if (stacks->size_a > 1 && stacks->size_b > 1)
	{
		ra_no_print(stacks);
		rb_no_print(stacks);
		write(1, "rr\n", 3);
	}
}
