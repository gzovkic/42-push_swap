/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_rt_uppercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:16:56 by gzovkic           #+#    #+#             */
/*   Updated: 2024/10/28 12:29:41 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_rt_uppercase(unsigned long num)
{
	char	*hex_uppercase;
	int		count;
	int		check;

	check = 0;
	count = 0;
	hex_uppercase = "0123456789ABCDEF";
	if (num >= 16)
	{
		check = ft_puthex_rt_uppercase(num / 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = ft_putchar_rt(hex_uppercase[num % 16]);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
