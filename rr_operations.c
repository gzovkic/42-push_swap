/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrijel <gabrijel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:30:09 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/16 11:03:14 by gabrijel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_no_print(t_stacks *stacks)
{
	int	temp;
	int	count;

	if (stacks->size_a > 1)
	{
		temp = stacks->stack_a[stacks->size_a - 1];
		count = stacks->size_a - 1;
		while (count > 0)
		{
			stacks->stack_a[count] = stacks->stack_a[count - 1];
			count--;
		}
		stacks->stack_a[0] = temp;
	}
}

void	rrb_no_print(t_stacks *stacks)
{
	int	temp;
	int	count;

	if (stacks->size_b > 1)
	{
		temp = stacks->stack_b[stacks->size_b - 1];
		count = stacks->size_b - 1;
		while (count > 0)
		{
			stacks->stack_b[count] = stacks->stack_b[count - 1];
			count--;
		}
		stacks->stack_b[0] = temp;
	}
}

void	rra(t_stacks *stacks)
{
	rra_no_print(stacks);
	write(1, "rra\n", 3);
}

void	rrb(t_stacks *stacks)
{
	rrb_no_print(stacks);
	write(1, "rrb\n", 3);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	write(1, "rrr\n", 3);
}
