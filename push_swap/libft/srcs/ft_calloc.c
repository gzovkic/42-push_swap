/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:11:16 by gzovkic           #+#    #+#             */
/*   Updated: 2025/01/24 10:43:27 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	num;
	void	*ptr;

	num = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (num < count * size)
	{
		ft_bzero(ptr + num, size);
		num = num + size;
	}
	return (ptr);
}
