/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:11:49 by jbellucc          #+#    #+#             */
/*   Updated: 2025/01/21 11:11:56 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int s)
{
	while (*str)
	{
		if (*str == (char)s)
			return ((char *)str);
		str ++;
	}
	if (s == '\0' && (char)s == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s3;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s3)
		return (NULL);
	while (s1 && *s1)
		*s3 ++ = *s1 ++;
	while (s2 && *s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (s3 - (s1len + s2len));
}

size_t	ft_strlen(char *str)
{
	size_t	p;

	p = 0;
	while (str && str[p] != '\0' )
		p ++;
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	p;

	p = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (len)
	{
		s2[p++] = s[start++];
		len --;
	}
	s2[p] = '\0';
	return (s2);
}
