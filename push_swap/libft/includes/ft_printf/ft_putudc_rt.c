/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudc_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:15:43 by gzovkic           #+#    #+#             */
/*   Updated: 2025/01/24 10:45:16 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putudc_rt(unsigned int n)
{
	int		count;
	int		check;
	char	c;

	check = 0;
	count = 0;
	if (n >= 10)
	{
		check = ft_putudc_rt(n / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (++count);
}
