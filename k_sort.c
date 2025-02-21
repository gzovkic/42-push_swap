/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:03:20 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/19 10:30:12 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stacks *stacks)
{
	int	count;
	int	range;

	count = 0;
	range = ft_sqrt(stacks->size_a) * 1.6;
	while (stacks->size_a > 0)
	{
		if (stacks->stack_a[0] <= count)
		{
			pb(stacks);
			rb(stacks);
			count++;
		}
		else if (stacks->stack_a[0] < count + range)
		{
			pb(stacks);
			count++;
		}
		else
		{
			ra(stacks);
		}
	}
}

int	get_moves(t_stacks *stacks)
{
	int	max_index;
	int	count;
	int	forward_moves;
	int	reverse_moves;

	max_index = 0;
	count = 0;
	while (count < stacks->size_b)
	{
		if (stacks->stack_b[count] > stacks->stack_b[max_index])
			max_index = count;
		count++;
	}
	forward_moves = max_index;
	reverse_moves = stacks->size_b - max_index;
	if (forward_moves <= reverse_moves)
		return (forward_moves);
	else
		return (-reverse_moves);
}

void	push_back(t_stacks *stacks)
{
	int	moves;

	while (stacks->size_b > 0)
	{
		moves = get_moves(stacks);
		if (moves > 0)
		{
			while (moves-- > 0)
			{
				rb(stacks);
			}
		}
		else
		{
			moves = -moves;
			while (moves-- > 0)
			{
				rrb(stacks);
			}
		}
		pa(stacks);
	}
}

void	set_index(t_stacks *stacks)
{
	int	swap;
	int	count;

	count = 0;
	while (count < stacks->size_a)
	{
		swap = 0;
		while (swap < stacks->size_a)
		{
			if (stacks->stack_a[count] == stacks->index_stack[swap])
			{
				stacks->stack_a[count] = swap;
				break ;
			}
			swap++;
		}
		count++;
	}
	count = 0;
	while (count < stacks->size_i)
	{
		stacks->index_stack[count] = count;
		count++;
	}
}

void	k_sort(t_stacks *stacks)
{
	if (stacks->size_a < 6)
	{
		if (stacks->size_a == 1)
			return ;
		else if (check_sorted(stacks) == EXIT_SUCCESS)
			return ;
		else if (stacks->size_a == 2)
			sort_two(stacks);
		else if (stacks->size_a == 3)
			sort_three(stacks);
		else if (stacks->size_a == 4)
			sort_four(stacks);
		else if (stacks->size_a == 5)
			sort_five(stacks);
		return ;
	}
	else
	{
		if (check_sorted(stacks) == EXIT_SUCCESS)
			return ;
		set_index(stacks);
		push_b(stacks);
		push_back(stacks);
	}
}
