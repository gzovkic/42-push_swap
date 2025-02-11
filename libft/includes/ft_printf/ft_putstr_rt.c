/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:26:01 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:08:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_rt(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen_p(s);
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}
