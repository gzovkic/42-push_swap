/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:27:50 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 15:21:42 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *intput, ...);
static int	check_type(va_list args, char c);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		total_print;
	int		check;

	check = 0;
	total_print = 0;
	count = 0;
	va_start(args, format);
	while (format[count] != '\0')
	{
		if (format[count] == '%' && format[count + 1] != '\0')
		{
			check = check_type(args, format[count + 1]);
			count++;
		}
		else if (format[count] != '%')
			check = ft_putchar_rt(format[count]);
		if (check == -1)
			return (-1);
		total_print += check;
		count++;
	}
	va_end(args);
	return (total_print);
}

static int	check_type(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == '%')
		len = ft_putchar_rt('%');
	else if (c == 'c')
		len = ft_putchar_rt(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_rt(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr_rt(va_arg(args, char *));
	else if (c == 'x')
		len = ft_puthex_rt_lowercase(va_arg(args, unsigned int));
	else if (c == 'X')
		len = ft_puthex_rt_uppercase(va_arg(args, unsigned int));
	else if (c == 'p')
		len = ft_putptr_rt(va_arg(args, void *));
	else if (c == 'u')
		len = ft_putudc_rt(va_arg(args, unsigned int));
	return (len);
}
