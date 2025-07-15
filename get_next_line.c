/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:45:53 by chantas           #+#    #+#             */
/*   Updated: 2025/07/15 22:57:19 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *buffer, char **line, int fd)
{
	int		i;
	char	*temp;

	read(fd, buffer, BUFFER_SIZE);
	i = ft_strchr(buffer, '\n');
	while (!i)
	{
		read(fd, temp, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, temp);
		i = ft_strchr(buffer, '\n');
		if (i)
		{
			*line = ft_substr(buffer, i);
		}
	}
	*line = ft_substr(buffer, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !buffer || read(fd, 0, 0) <= 0)
		return (free(buffer), NULL);
	line = next_line(buffer, &line, fd);
	return (line);
}
