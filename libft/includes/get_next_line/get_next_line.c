/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:54:14 by gzovkic           #+#    #+#             */
/*   Updated: 2025/01/24 10:50:04 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*make_str(char *buffer);
char	*leftover_check(char *buffer);
char	*line_return(char **container);
int		read_count(int fd, char **container);

char	*get_next_line(int fd)
{
	char		*rt_str;
	int			byte_length;
	static char	*container;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!container)
		container = ft_calloc(1, sizeof(char));
	if (!container)
		return (NULL);
	byte_length = read_count(fd, &container);
	if (byte_length < 0 || (byte_length == 0 && (!container || !*container)))
	{
		free(container);
		container = NULL;
		return (NULL);
	}
	rt_str = line_return(&container);
	return (rt_str);
}

char	*line_return(char **container)
{
	char	*rt_str;
	char	*temp;

	rt_str = make_str(*container);
	if (!rt_str)
	{
		free(*container);
		*container = NULL;
		return (NULL);
	}
	temp = leftover_check(*container);
	free(*container);
	*container = temp;
	return (rt_str);
}

int	read_count(int fd, char **container)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*str2;
	int		buffer_check;

	buffer_check = read(fd, buffer, BUFFER_SIZE);
	if (buffer_check < 0)
		return (-1);
	while (buffer_check > 0)
	{
		buffer[buffer_check] = '\0';
		str2 = ft_strjoin_gnl(*container, buffer);
		free(*container);
		if (!str2)
			return (*container = NULL, -1);
		*container = str2;
		if (ft_strchr(*container, '\n'))
			break ;
		buffer_check = read(fd, buffer, BUFFER_SIZE);
	}
	return (buffer_check);
}

char	*make_str(char *buffer)
{
	char			*str;
	unsigned int	count;
	unsigned int	count2;

	count = 0;
	count2 = 0;
	while (buffer[count] != '\n' && buffer[count] != '\0')
		count++;
	if (buffer[count] == '\n')
		str = ft_calloc(count + 2, sizeof(char));
	else
		str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (count > count2)
	{
		str[count2] = buffer[count2];
		count2++;
	}
	if (buffer[count2] == '\n')
		str[count2] = '\n';
	return (str);
}

char	*leftover_check(char *buffer)
{
	int		count;
	int		count2;
	char	*str;

	count = 0;
	count2 = 0;
	while (buffer[count] != '\n' && buffer[count] != '\0')
		count++;
	if (buffer[count] == '\0')
		return (NULL);
	str = ft_calloc(ft_strlen_gnl(buffer) - count + 1, sizeof(char));
	if (!str)
		return (NULL);
	count++;
	while (buffer[count] != '\0')
	{
		str[count2] = buffer[count];
		count++;
		count2++;
	}
	return (str);
}
// int	main(void)
// {
// 	const char *file = "test.txt";

// 	int fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	close(fd);
// 	return (0);
// }