/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:50:29 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/18 15:18:37 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_no_print(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = temp;
	}
}

void	sb_no_print(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = temp;
	}
}

void	sa(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		sa_no_print(stacks);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		sb_no_print(stacks);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stacks *stacks)
{
	if (stacks->size_a > 1 && stacks->size_b > 1)
	{
		sa_no_print(stacks);
		sb_no_print(stacks);
		write(1, "ss\n", 3);
	}
}
