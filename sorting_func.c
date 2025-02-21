/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:02:56 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/21 13:05:52 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort_stack(int *stack_a_int, int stack_a_length)
{
	int	count;
	int	temp;
	int	passes;

	passes = stack_a_length - 1;
	while (passes > 0)
	{
		count = 0;
		while (count < passes)
		{
			if (stack_a_int[count] > stack_a_int[count + 1])
			{
				temp = stack_a_int[count];
				stack_a_int[count] = stack_a_int[count + 1];
				stack_a_int[count + 1] = temp;
			}
			count++;
		}
		passes--;
	}
	return (stack_a_int);
}

void	sort_two(t_stacks *stacks)
{
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a[0];
	b = stacks->stack_a[1];
	c = stacks->stack_a[2];
	if (a > b && a < c)
		sa(stacks);
	else if (a > c && b > c)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (a > b && b < c && a > c)
		ra(stacks);
	else if (a < b && a > c)
		rra(stacks);
	else if (a < b && b > c && a < c)
	{
		sa(stacks);
		ra(stacks);
	}
}

void	sort_four(t_stacks *stacks)
{
	int	min;
	int	count;

	min = find_min(stacks);
	count = 0;
	while (stacks->stack_a[0] != min)
	{
		ra(stacks);
		count++;
	}
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

void	sort_five(t_stacks *stacks)
{
	int	min;
	int	count;

	min = find_min(stacks);
	count = 0;
	while (stacks->stack_a[0] != min)
	{
		ra(stacks);
		count++;
	}
	pb(stacks);
	sort_four(stacks);
	pa(stacks);
}
