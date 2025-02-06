/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:19:22 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	count2;

	count = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[count]);
	while (haystack[count] != '\0' && count < len)
	{
		count2 = 0;
		while (haystack[count + count2] == needle[count2] && (count
				+ count2) < len)
		{
			if (needle[count2 + 1] == '\0')
				return ((char *)&haystack[count]);
			count2++;
		}
		count++;
	}
	return (NULL);
}
