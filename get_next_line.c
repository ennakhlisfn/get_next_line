/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:27:50 by sennakhl          #+#    #+#             */
/*   Updated: 2023/12/27 15:17:57 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

int	new_line(char *line)
{
	size_t	i;

	if (line == NULL)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*fill_line(char *line, char *buf)
{
	size_t	i;
	size_t	l;
	size_t	j;
	char	*tmp;

	l = ft_strlen(line);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	tmp = (char *)ft_calloc((l + i + 2), sizeof(char));
	if (!tmp)
		return (free(line), (NULL));
	ft_strcpy(tmp, line);
	free(line);
	j = 0;
	while (j <= i)
	{
		tmp[l + j] = buf[j];
		j++;
	}
	l = ft_strlen(buf + i);
	ft_strcpy(buf, buf + j);
	ft_bzero(buf + l, j);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			*line;
	size_t			l;
	ssize_t			q;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	l = BUFFER_SIZE;
	line = (char *)ft_calloc(l, sizeof(char));
	if (!line)
		return (NULL);
	line = fill_line(line, buffer);
	if (!line)
		return (NULL);
	while (new_line(line))
	{
		q = read(fd, buffer, l);
		if (q <= 0)
			return (free(line), (NULL));
		line = fill_line(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("test.txt",O_RDONLY);
	int	i = 1;
	char *line=get_next_line(fd);
	while (line)
	{
		printf("%d-->%s",i,line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	
	close(fd);

	return (0);
}
*/
