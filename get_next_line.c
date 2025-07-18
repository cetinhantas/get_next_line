/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:45:53 by chantas           #+#    #+#             */
/*   Updated: 2025/07/18 17:40:59 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char **buffer, char *temp, char *line, int fd)
{
	read(fd, temp, BUFFER_SIZE);
	while (!ft_strchr(temp, '\n'))
	{
		*buffer = ft_strjoin(*buffer, temp);
		if (read(fd, temp, BUFFER_SIZE))
			*buffer = ft_strjoin(*buffer, temp);
		else
		{
			line = ft_substr(*buffer, ft_strlen(*buffer));
			return (free(*buffer), free(temp), line);
		}
	}
	if (!**buffer)
		line = ft_substr(temp, ft_strchr(temp, '\n'));
	else
		line = ft_substr(*buffer, ft_strchr(*buffer, '\n'));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	temp = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		buffer = ft_strdup("");
	if (fd < 0 || !temp || !buffer || read(fd, 0, 0) <= 0)
		return (free(buffer), free(buffer), NULL);
	temp[BUFFER_SIZE] = 0;
	line = next_line(&buffer, temp, line, fd);
	return (line);
}
