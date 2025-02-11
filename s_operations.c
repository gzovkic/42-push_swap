/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:50:29 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/07 12:05:12 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stacks *stacks)
{
	int temp;
	
	if(stacks->size_a > 1)
	{
		temp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = temp;
		ft_printf("sa\n");
	}
}

void sb(t_stacks *stacks)
{
	int temp;
	
	if(stacks->size_b > 1)
	{
		temp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = temp;
		ft_printf("sb\n");
	}
}

void	ss(t_stacks *stacks)
{
	if(stacks->size_a > 1 && stacks->size_b > 1)
	{
		sa(stacks);
		sb(stacks);
		ft_printf("ss\n");
	}
}
