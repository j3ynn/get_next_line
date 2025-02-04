/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:11:10 by jbellucc          #+#    #+#             */
/*   Updated: 2025/01/21 11:11:20 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//deve salvare quello che ha dopo lo \n nella static
//deve ritornare tutto quello che ha prima dello \n
char	*ft_extraction_storage(char storage[BUFFER_SIZE])
{
	int		i;
	int		p;
	char	*str;

	p = 0;
	while (storage[p] != '\n')
		p ++;
	str = ft_substr(storage, 0, p + 1);
	i = 0;
	p ++;
	while (p < BUFFER_SIZE && storage[p])
	{
		storage[i++] = storage[p];
		storage[p++] = 0;
	}
	while (i < BUFFER_SIZE && storage[i])
		storage[i++] = '\0';
	return (str);
}

//deve leggere la linea tenendo anche quello che ha dopo la \n
int	ft_check_storage(char storage[BUFFER_SIZE], char **line)
{
	char	*line2;
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strchr(storage, '\n') != 0)
	{
		line2 = ft_extraction_storage(storage);
		tmp = *line;
		*line = ft_strjoin(*line, line2);
		free(line2);
		free(tmp);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, storage);
		free(tmp);
		while (i < BUFFER_SIZE)
			storage[i++] = 0;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	storage[1024][BUFFER_SIZE];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (ft_check_storage(storage[fd], &line))
			return (line);
		bytes = read(fd, storage[fd], BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (bytes == 0)
		{
			if (ft_strlen(line) != 0)
				return (line);
			free(line);
			return (NULL);
		}
	}
}
