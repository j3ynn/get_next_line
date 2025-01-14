/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:49:34 by jbellucc          #+#    #+#             */
/*   Updated: 2025/01/14 11:49:53 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//per controllare se siamo arrivati alla fine del file
char	*ft_join_tot(char *buffer, char *tot, int count_bite)
{
	char	*temp;

	if (count_bite <= 0)
	{
		if (count_bite < 0 && !*tot)
		{
			free(tot);
				return (NULL);
		}
		return (tot);
	}
	buffer[count_bite] = '\0';
	temp = ft_strjoin(tot, buffer, 1);
	return (temp);
}

char	*ft_strjoin(char *tot, char *buffer, int n)
{
	size_t	totlen;
	size_t	bufferlen;
	char	*s;

	totlen = ft_strlen(tot);
	bufferlen = ft_strlen(buffer);
	s = (char *)malloc(sizeof(char) * (totlen + bufferlen + 1));
	if (!tot || !buffer || !s)
		return (NULL);
	while (*tot)
		*s ++ = *tot ++;
	while (*buffer)
		*s ++ = *buffer ++;
	*s = '\0';
	if (n)
		free(tot);
	return (s - (totlen + bufferlen));
}

char	*ft_read_cat(char *remainder, int fd)
{
	char	*buffer;
	char	*tot;
	int		count_bite;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	tot = ft_join("", remainder, 0);
	count_bite = 0;
	while (!(*(buffer++) != '\n'))
	{
		count_bite = read(fd, buffer, BUFFER_SIZE);
		tot = ft_join_tot(buffer, tot, count_bite);
		if (!tot || count_bite == 0)
				break;
	}
	free(buffer);
	return (tot);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_cat(remainder, fd);
	if (!buffer)
		return (NULL);
	line = ft_strdup(buffer, size);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	remainder = ft_get_remainder(buffer, remainder);
	free(buffer);
	return (line);
}
