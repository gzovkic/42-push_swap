/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:38:05 by gzovkic           #+#    #+#             */
/*   Updated: 2025/01/28 18:14:27 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc_gnl(size_t count, size_t size);
void	ft_bzero_gnl(void *s, size_t n);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
int		ft_strlen_gnl(const char *c);
char	*ft_strchr_gnl(const char *s, int c);

void	*ft_calloc_gnl(size_t count, size_t size)
{
	size_t	num;
	void	*ptr;

	num = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (num < count * size)
	{
		ft_bzero_gnl(ptr + num, size);
		num = num + size;
	}
	return (ptr);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t			count;
	unsigned char	*loc;

	loc = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		loc[count] = 0;
		count++;
	}
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		count;
	int		count2;
	int		sumstr;
	char	*newstr;

	count = 0;
	count2 = 0;
	sumstr = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	newstr = ft_calloc_gnl(sumstr + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (count + count2 < sumstr)
	{
		if (count < ft_strlen_gnl(s1))
		{
			newstr[count] = s1[count];
			count++;
		}
		else if (count2 < ft_strlen_gnl(s2))
		{
			newstr[count + count2] = s2[count2];
			count2++;
		}
	}
	return (newstr);
}

int	ft_strlen_gnl(const char *c)
{
	int	count;

	count = 0;
	while (c[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr_gnl(const char *s, int c)
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
