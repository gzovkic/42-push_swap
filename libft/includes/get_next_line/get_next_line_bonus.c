/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:36:26 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/03 10:47:26 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
char	*make_str(char *buffer);
char	*leftover_check(char *buffer);
char	*line_return(char **container);
int		read_count(int fd, char **container);

char	*get_next_line(int fd)
{
	char		*rt_str;
	int			byte_length;
	static char	*container[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!container[fd])
		container[fd] = ft_calloc_gnl(1, sizeof(char));
	if (!container[fd])
		return (NULL);
	byte_length = read_count(fd, &container[fd]);
	if (byte_length < 0)
	{
		free(container[fd]);
		container[fd] = NULL;
		return (NULL);
	}
	if (byte_length == 0 && (!container[fd] || !*container[fd]))
	{
		free(container[fd]);
		container[fd] = NULL;
		return (NULL);
	}
	rt_str = line_return(&container[fd]);
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
		if (ft_strchr_gnl(*container, '\n'))
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
		str = ft_calloc_gnl(count + 2, sizeof(char));
	else
		str = ft_calloc_gnl(count + 1, sizeof(char));
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
	str = ft_calloc_gnl(ft_strlen_gnl(buffer) - count + 1, sizeof(char));
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
// 	int fd1 = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);

// 	if (fd1 == -1 || fd2 == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	char *line;

// 	while (1)
// 	{
// 		line = get_next_line(fd1);
// 		if (line)
// 		{
// 			printf("From file1.txt: %s", line);
// 			free(line);
// 		}
// 		line = get_next_line(fd2);
// 		if (line)
// 		{
// 			printf("From file2.txt: %s", line);
// 			free(line);
// 		}
// 		if (line == NULL && get_next_line(fd1) == NULL
// 			&& get_next_line(fd2) == NULL)
// 			break ;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }