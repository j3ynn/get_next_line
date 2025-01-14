/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:50:14 by jbellucc          #+#    #+#             */
/*   Updated: 2025/01/14 11:50:21 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

void	ft_get_remainder(char *buffer, char *str);
size_t	ft_strlen(const char *str);
char	*ft_join_tot(char *buffer, char *tot, int count_bite);
char	*ft_strjoin(char *tot, char *buffer, int n);
char	*ft_read_cat(char *remainder, int fd);
char	*get_next_line(int fd);
char	*ft_strdup(const char *str, size_t size);

#endif
