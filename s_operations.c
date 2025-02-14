/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:50:29 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/14 18:33:53 by gzovkic          ###   ########.fr       */
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
	sa_no_print(stacks);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	sb_no_print(stacks);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	if (stacks->size_a > 1 && stacks->size_b > 1)
	{
		sa_no_print(stacks);
		sb_no_print(stacks);
		ft_printf("ss\n");
	}
}
