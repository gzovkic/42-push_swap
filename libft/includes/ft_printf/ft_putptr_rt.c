/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:18:23 by gzovkic           #+#    #+#             */
/*   Updated: 2024/10/28 12:29:47 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_rt(void *ptr)
{
	int				count;
	int				check;
	unsigned long	ptr_str;

	check = 0;
	count = 0;
	ptr_str = ((unsigned long)ptr);
	if (!ptr_str)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	check = write(1, "0x", 2);
	if (check == -1)
		return (-1);
	count += check;
	check = ft_puthex_rt_lowercase(ptr_str);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
