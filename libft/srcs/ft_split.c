/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:21:19 by gzovkic           #+#    #+#             */
/*   Updated: 2025/01/15 16:53:48 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	get_sep(char const *s, char c);
static int		copystring(char **newstr, char const *s, char sep);
static int		malloc_string(char **newstr, int arraylocation, int countStr);

char	**ft_split(char const *s, char c)
{
	int		count;
	int		check;
	char	**newstr;

	check = 0;
	if (s == NULL)
		return (NULL);
	count = get_sep(s, c);
	newstr = ft_calloc(count + 1, sizeof(char *));
	if (!newstr)
		return (NULL);
	check = copystring(newstr, s, c);
	if (check == 1)
		return (NULL);
	return (newstr);
}

static size_t	get_sep(char const *s, char c)
{
	int	count;
	int	sep;
	int	in_sep;

	count = 0;
	sep = 0;
	in_sep = 1;
	while (s[count] != '\0')
	{
		in_sep = 0;
		while (s[count] == c && s[count] != '\0')
			count++;
		while (s[count] != c && s[count] != '\0')
		{
			if (in_sep == 0)
			{
				sep++;
				in_sep = 1;
			}
			count++;
		}
	}
	return (sep);
}

static int	copystring(char **newstr, char const *s, char sep)
{
	int	arraylocation;
	int	count;
	int	countstr;

	count = 0;
	countstr = 0;
	arraylocation = 0;
	while (s[count] != '\0')
	{
		countstr = 0;
		while (*s == sep && *s != '\0')
			s++;
		while (s[countstr] != sep && s[countstr] != '\0')
			countstr++;
		if (countstr > 0)
		{
			if (malloc_string(newstr, arraylocation, countstr + 1) == 1)
				return (1);
			ft_strlcpy(newstr[arraylocation], s, countstr + 1);
			s = s + countstr;
			arraylocation++;
		}
	}
	newstr[arraylocation] = NULL;
	return (0);
}

static int	malloc_string(char **newstr, int arraylocation, int countStr)
{
	int	count;

	count = 0;
	newstr[arraylocation] = ft_calloc(countStr, sizeof(char));
	if (newstr[arraylocation] == NULL)
	{
		while (count < arraylocation)
		{
			free(newstr[count]);
			count++;
		}
		free(newstr);
		return (1);
	}
	return (0);
}
