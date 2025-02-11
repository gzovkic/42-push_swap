/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:45:43 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	strlen;
	size_t	mallocsize;
	char	*newstr;

	count = 0;
	strlen = ft_strlen(s);
	if (start > strlen)
	{
		newstr = ft_calloc(1, sizeof(char));
		return (newstr);
	}
	if (len > strlen - start)
		mallocsize = strlen - start;
	else
		mallocsize = len;
	newstr = ft_calloc(mallocsize + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[start + count] && mallocsize > count)
	{
		newstr[count] = s[start + count];
		count++;
	}
	return (newstr);
}
