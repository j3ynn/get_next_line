/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:50:45 by jbellucc          #+#    #+#             */
/*   Updated: 2025/01/14 11:50:48 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	p;

	p = 0;
	if (!str)
		return (0);
	while (str[p] != '\0')
		p++;
	return (p);
}

char	*ft_strdup(const char *str, size_t size)
{
	char	*s_dup;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen(str);
	s_dup = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	while (i < size)
		s_dup[j++] = str[i++];
	if (str[i] == '\n')
		s_dup[j - 1] = '\n';
	s_dup[j] = '\0';
	return (s_dup);
}

void	ft_get_remainder(char *buffer, char *str)
{
	size_t	p1;
	size_t	p2;

	while (buffer[p1] != '\0' && buffer[p1] != '\n')
		p1 ++;
	if (buffer[p1] == '\n')
		p1 ++;
	while (buffer[p1])
	{
		str[p2] = buffer[p1]
		p1 ++;
		p2 ++;
	}
	str[p2] = '\0';
}
