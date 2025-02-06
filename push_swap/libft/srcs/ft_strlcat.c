/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:17:11 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dstlen;
	size_t	srclen;

	count = 0;
	dstlen = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	while (dst[dstlen] != '\0' && dstlen < dstsize)
		dstlen++;
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	while (src[count] != '\0' && dstsize - 1 > dstlen + count)
	{
		dst[dstlen + count] = src[count];
		count++;
	}
	dst[dstlen + count] = '\0';
	return (dstlen + srclen);
}
