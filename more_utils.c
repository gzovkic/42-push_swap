/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:53:19 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/21 14:52:16 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stacks *stacks)
{
	int	min;
	int	count;

	min = stacks->stack_a[0];
	count = 0;
	while (count < stacks->size_a)
	{
		if (stacks->stack_a[count] < min)
			min = stacks->stack_a[count];
		count++;
	}
	return (min);
}

int	check_sorted(t_stacks *stack)
{
	int	count;

	count = 0;
	while (stack->stack_a[count] == stack->index_stack[count]
		&& count < stack->size_a - 1)
		count++;
	if (count == stack->size_a - 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_sqrt(int nb)
{
	int	sqr_root;

	if (nb < 0)
		return (0);
	sqr_root = 0;
	while (sqr_root * sqr_root <= nb)
	{
		if (sqr_root * sqr_root <= nb && (sqr_root + 1) * (sqr_root + 1) >= nb)
			return (sqr_root);
		sqr_root++;
	}
	return (0);
}

void	init_default_stacks(t_stacks *stacks)
{
	stacks->size_a = 0;
	stacks->size_b = 0;
	stacks->size_i = 0;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->index_stack = NULL;
}
