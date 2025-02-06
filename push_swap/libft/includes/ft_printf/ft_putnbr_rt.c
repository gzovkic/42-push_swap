/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:18:58 by gzovkic           #+#    #+#             */
/*   Updated: 2024/10/28 12:29:44 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_rt(int n)
{
	int		count;
	int		check;
	char	c;
	long	nb;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		check = ft_putnbr_rt(nb / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (++count);
}
