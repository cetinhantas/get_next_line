/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chantas <chantas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:24:09 by chantas           #+#    #+#             */
/*   Updated: 2025/07/19 19:40:42 by chantas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
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
		i++;
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
	ptr = (char *)ft_calloc(s1len + s2len + 1);
	if (!ptr)
		return (NULL);
	while (s1len)
	{
		s1len--;
		ptr[s1len] = s1[s1len];
	}
	s1len = ft_strlen(s1);
	while (s2len)
	{
		s2len--;
		ptr[s1len + s2len] = s2[s2len];
	}
	return (free(s1), ptr);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*ptr;

	ptr = (char *)ft_calloc(len + 1);
	if (!ptr)
		return (NULL);
	while (len)
	{
		len--;
		ptr[len] = s[start + len];
	}
	return (ptr);
}

char	*ft_calloc(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(size);
	if (!ptr)
		return (NULL);
	while (size)
	{
		size--;
		ptr[size] = 0;
	}
	return (ptr);
}
