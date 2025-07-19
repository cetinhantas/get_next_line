/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:45:53 by chantas           #+#    #+#             */
/*   Updated: 2025/07/19 19:40:31 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	pass_line(char **buffer, char **line)
{
	char	*tmp;
	char	*linetmp;
	int		i;
	int		len;

	i = ft_strchr(*buffer, '\n');
	len = ft_strlen(*buffer);
	if (i)
	{
		*line = ft_substr(*buffer, 0, i);
		tmp = ft_substr(*buffer, i, len - i);
		free(*buffer);
		*buffer = tmp;
	}
	else
	{
		linetmp = ft_substr(*buffer, 0, len);
		free(*buffer);
		*buffer = NULL;
		*line = linetmp;
	}
}

static void	find_line(char **buffer, char *temp, char **line, int fd)
{
	while (1)
	{
		if (read(fd, temp, BUFFER_SIZE) <= 0)
			break ;
		*buffer = ft_strjoin(*buffer, temp);
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	free(temp);
	if (!*buffer || !**buffer)
	{
		*line = NULL;
		return ;
	}
	pass_line(buffer, line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	temp = ft_calloc(BUFFER_SIZE + 1);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1);
	if (!temp || !buffer[fd])
		return (NULL);
	find_line(&buffer[fd], temp, &line, fd);
	if (!line || !*line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
