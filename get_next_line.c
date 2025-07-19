/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:45:53 by chantas           #+#    #+#             */
/*   Updated: 2025/07/19 17:48:29 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	pass_line(char **buffer, char **line);
static void	find_line(char **buffer, char *temp, char **line, int fd);

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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	temp = ft_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		buffer = ft_calloc(1);
	if (fd < 0 || !temp || !buffer)
		return (NULL);
	find_line(&buffer, temp, &line, fd);
	if (!line || !*line)
	{
		free(buffer);
		buffer = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
