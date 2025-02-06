/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:08:21 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				count;
	int				last;
	unsigned char	c2;

	c2 = (unsigned char)c;
	count = 0;
	last = -1;
	while (s[count] != '\0')
	{
		if (s[count] == c2)
			last = count;
		count++;
	}
	if (c2 == '\0')
		return ((char *)&s[count]);
	if (last != -1)
		return ((char *)&s[last]);
	return (NULL);
}
