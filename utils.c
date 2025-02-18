/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:07:24 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/18 15:49:05 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_index(char *map[])
{
	int	index;

	index = 0;
	while (map[index] != NULL)
		index++;
	return (index);
}

void	free_split(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
	{
		free(map[count]);
		count++;
	}
	free(map);
}

void	check_argument(char *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i])
	{
		while (stack_a[i] && (stack_a[i] == ' ' || (stack_a[i] >= 9
					&& stack_a[i] <= 13)))
			i++;
		if (!stack_a[i])
			break ;
		if (stack_a[i] == '-')
		{
			if (!(stack_a[i + 1] >= '0' && stack_a[i + 1] <= '9'))
				printf_exit_and_str("invalid input", NULL, stack_a);
			i++;
		}
		if (!(stack_a[i] >= '0' && stack_a[i] <= '9'))
			printf_exit_and_str("invalid input", NULL, stack_a);
		while (stack_a[i] && (stack_a[i] >= '0' && stack_a[i] <= '9'))
			i++;
		if (stack_a[i] && !(stack_a[i] == ' ' || (stack_a[i] >= 9
					&& stack_a[i] <= 13)))
			printf_exit_and_str("invalid input", NULL, stack_a);
	}
}

long	ft_atolo(const char *str)
{
	int		count;
	long	final;
	int		check;

	count = 0;
	final = 0;
	check = 1;
	while (str[count] == 32 || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (str[count] == '-')
	{
		check = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		final = final * 10 + (str[count] - '0');
		count++;
	}
	return (final * check);
}
