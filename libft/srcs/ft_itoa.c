/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:17:34 by gzovkic           #+#    #+#             */
/*   Updated: 2025/01/24 10:43:47 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*make_str(int n);
static int	lengthstr(int n);
static char	*write_str(char *str, long number, int len);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	number;

	number = n;
	if (n == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	str = make_str(n);
	if (!str)
		return (NULL);
	len = lengthstr(n) - 1;
	return (write_str(str, number, len));
}

static char	*make_str(int n)
{
	int		size;
	char	*str;
	long	num;

	num = n;
	size = 0;
	if (n < 0)
		size++;
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static int	lengthstr(int n)
{
	int		size;
	long	num;

	num = n;
	size = 0;
	if (n < 0)
		size++;
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

static char	*write_str(char *str, long number, int len)
{
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	str[len + 1] = '\0';
	while (number > 0)
	{
		str[len] = number % 10 + '0';
		number = number / 10;
		len--;
	}
	return (str);
}
