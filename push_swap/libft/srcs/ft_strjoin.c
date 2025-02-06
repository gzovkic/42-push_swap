/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:29:55 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		count2;
	int		sumstr;
	char	*newstr;

	count = 0;
	count2 = 0;
	sumstr = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc(sumstr + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (count + count2 < sumstr)
	{
		if (count < ft_strlen(s1))
		{
			newstr[count] = s1[count];
			count++;
		}
		else if (count2 < ft_strlen(s2))
		{
			newstr[count + count2] = s2[count2];
			count2++;
		}
	}
	return (newstr);
}
