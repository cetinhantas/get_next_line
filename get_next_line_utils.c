/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:09 by chantas           #+#    #+#             */
/*   Updated: 2025/07/18 17:06:11 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i + 1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*ptr;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc(s1len + s2len + 1);
	if (!ptr)
		return (NULL);
	ptr[s1len + s2len] = 0;
	while (s1len)
	{
		s1len--;
		ptr[s1len] = s1[s1len];
	}
	while (s2len)
	{
		s2len--;
		ptr[s2len] = s2[s2len];
	}
	return (free(s1), ptr);
}

char	*ft_substr(char *s, size_t len)
{
	char	*ptr;

	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	while (len)
	{
		len--;
		ptr[len] = s[len];
	}
	return (ptr);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	while (len)
	{
		len--;
		ptr[len] = s[len];
	}
	return (ptr);
}
