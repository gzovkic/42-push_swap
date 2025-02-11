/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:07:24 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/10 11:00:06 by gzovkic          ###   ########.fr       */
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
	int	count;
	int	number_flag;

	number_flag = 0;
	count = 0;
	while (stack_a[count] != '\0')
	{
		if (stack_a[count] == 32 || (stack_a[count] >= 9
				&& stack_a[count] <= 13))
			count++;
		else if (!(stack_a[count] >= '0' && stack_a[count] <= '9'))
			printf_and_exit("invalid input");
		if (stack_a[count] == '-')
		{
			count++;
			if (!(stack_a[count] >= '0' && stack_a[count] <= '9'))
				printf_and_exit("invalid input");
			while (stack_a[count] >= '0' && stack_a[count] <= '9')
			{
				number_flag = 1;
				count++;
			}
		}
		if (stack_a[count] >= '0' && stack_a[count] <= '9')
		{
			number_flag = 1;
			count++;
		}
	}
	if (number_flag == 0)
		printf_and_exit("no numbers in arguments");
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
