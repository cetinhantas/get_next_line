/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:45:53 by chantas           #+#    #+#             */
/*   Updated: 2025/07/18 23:37:06 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	*next_line(char **buffer, char *temp, char **line, int fd)
{
	int		i;
	int		len;

	while (1)
	{
		if (!read(fd, temp, BUFFER_SIZE))
			break ;
		*buffer = ft_strjoin(*buffer, temp);
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	i = ft_strchr(*buffer, '\n');
	len = ft_strlen(*buffer);
	if (i)
	{
		*line = ft_substr(*buffer, 0, i);
		*buffer = ft_substr(*buffer, i, len - i);
	}
	else
		*line = ft_substr(*buffer, 0, len);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	line = NULL;
	temp = ft_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		buffer = ft_calloc(1);
	if (fd < 0 || !temp || !buffer || read(fd, 0, 0) < 0)
		return (NULL);
	next_line(&buffer, temp, &line, fd);
	return (line);
}
