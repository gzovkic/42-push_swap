/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:25:34 by gzovkic           #+#    #+#             */
/*   Updated: 2024/10/11 13:32:11 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	count;
	int	final;
	int	check;

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
