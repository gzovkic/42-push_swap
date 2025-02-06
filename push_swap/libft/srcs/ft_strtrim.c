/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:07:19 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		find_last(char const *s1, char const *set);
static int		find_first(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		end;
	int		len;
	int		start;

	if (!s1 || !set || *s1 == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	start = find_first(s1, set);
	end = find_last(s1, set);
	if (start > end)
		len = 0;
	else
		len = (end - start + 1);
	newstr = ft_substr(s1, start, len);
	if (!newstr)
		return (NULL);
	return (newstr);
}

static int	find_first(char const *s1, char const *set)
{
	int	first;
	int	count;

	first = 0;
	count = 0;
	while (s1[first] != '\0' && set[count] != '\0')
	{
		if (s1[first] == set[count])
		{
			first++;
			count = 0;
		}
		else
			count++;
	}
	return (first);
}

static int	find_last(char const *s1, char const *set)
{
	int	last;
	int	count;

	count = 0;
	last = (ft_strlen(s1) - 1);
	while (s1[last] != '\0' && set[count] != '\0')
	{
		if (s1[last] == set[count])
		{
			last--;
			count = 0;
		}
		else
			count++;
	}
	return (last);
}
