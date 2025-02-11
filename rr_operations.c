/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:30:09 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/10 11:41:55 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stacks *stacks)
{
	int temp;
	int count;

	if(stacks->size_a > 1)
	{
		temp = stacks->stack_a[stacks->size_a - 1];
		count = stacks->size_a - 1;
		while(count > 0)
		{
			stacks->stack_a[count] = stacks->stack_a[count - 1];
			count--;
		}
		stacks->stack_a[0] = temp;
		ft_printf("rra\n");
	}
}

void rrb(t_stacks *stacks)
{
	int temp;
	int count;

	if(stacks->size_b > 1)
	{
		temp = stacks->stack_b[stacks->size_b - 1];
		count = stacks->size_b - 1;
		while(count > 0)
		{
			stacks->stack_b[count] = stacks->stack_b[count - 1];
			count--;
		}
		stacks->stack_b[0] = temp;
		ft_printf("rrb\n");
	}
}


void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_printf("rrr\n");
}
