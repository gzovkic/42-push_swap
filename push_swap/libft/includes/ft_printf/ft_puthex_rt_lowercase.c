/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_rt_lowercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:17:43 by gzovkic           #+#    #+#             */
/*   Updated: 2024/10/28 12:29:37 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_rt_lowercase(unsigned long num)
{
	char	*hex_lowercase;
	int		count;
	int		check;

	check = 0;
	count = 0;
	hex_lowercase = "0123456789abcdef";
	if (num >= 16)
	{
		check = ft_puthex_rt_lowercase(num / 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = ft_putchar_rt(hex_lowercase[num % 16]);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
