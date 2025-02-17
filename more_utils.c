/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:53:19 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/17 11:00:45 by gzovkic          ###   ########.fr       */
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
		&& count < stack->size_a)
		count++;
	if (count == stack->size_a)
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
