/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:02:56 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/14 18:33:57 by gzovkic          ###   ########.fr       */
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
