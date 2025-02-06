/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:46:11 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				count;
	unsigned char	c2;

	c2 = (unsigned char)c;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c2)
			return ((char *)&s[count]);
		count++;
	}
	if (c2 == '\0')
		return ((char *)&s[count]);
	return (NULL);
}
