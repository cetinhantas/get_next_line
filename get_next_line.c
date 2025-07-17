/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:45:53 by chantas           #+#    #+#             */
/*   Updated: 2025/07/17 03:05:26 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char **buffer, char *temp, char **line, int fd)
{
	int		i;
	int		bytes;

	read(fd, temp, BUFFER_SIZE);
	i = ft_strchr(temp, '\n');
	while (!i)
	{
		buffer = ft_strdup(temp);
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes)
			buffer = ft_strjoin(buffer, temp);
		else
		{
			i = ft_strlen(buffer);
			break ;
		}
		i = ft_strchr(buffer, '\n');
	}
	if (i)
		*line = ft_substr(buffer, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*line;
	static char	*temp;

	temp = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !temp || !buffer || read(fd, 0, 0) <= 0)
		return (free(buffer), NULL);
	temp[BUFFER_SIZE] = 0;
	line = next_line(&buffer, temp, &line, fd);
	return (line);
}
