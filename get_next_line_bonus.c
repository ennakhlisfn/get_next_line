/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:15:18 by sennakhl          #+#    #+#             */
/*   Updated: 2023/12/27 15:18:31 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	new_line(char *line)
{
	int	i;

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

char	*fill_line(char *line, char *buffer)
{
	size_t	i;
	size_t	l;
	size_t	j;
	char	*tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	l = ft_strlen(line);
	tmp = (char *)ft_calloc((l + i + 2), sizeof(char));
	if (!tmp)
		return ((free(line)), (NULL));
	ft_strcpy(tmp, line);
	free(line);
	j = 0;
	while (j <= i)
	{
		tmp[l + j] = buffer[j];
		j++;
	}
	l = ft_strlen(buffer + i);
	ft_strcpy(buffer, buffer + j);
	ft_bzero(buffer + l, j);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		q;
	static char	arr[1024][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!line)
		return (NULL);
	if (arr[fd][0])
		line = fill_line(line, arr[fd]);
	if (!line)
		return (NULL);
	while (new_line(line))
	{
		q = read(fd, arr[fd], BUFFER_SIZE);
		if (q <= 0)
			return ((free(line)), (NULL));
		line = fill_line(line, arr[fd]);
		if (!line)
			return (NULL);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("test1.txt",O_RDONLY);
	int fd2 = open("test2.txt",O_RDONLY);
	int fd3 = open("test3.txt",O_RDONLY);
	char *line;
	

	printf("%s",line = get_next_line(fd1));
	free(line);
	printf("%s",line = get_next_line(fd2));
	free(line);
	printf("%s",line = get_next_line(fd3));
	free(line);
	
	printf("%s",line = get_next_line(fd1));
	free(line);
	printf("%s",line = get_next_line(fd2));
	free(line);
	printf("%s",line = get_next_line(fd3));
	free(line);
	
	printf("%s",line = get_next_line(fd1));
	free(line);
	printf("%s",line = get_next_line(fd2));
	free(line);
	printf("%s",line = get_next_line(fd3));
	free(line);
	
	printf("%s",line = get_next_line(fd1));
	free(line);
	printf("%s",line = get_next_line(fd2));
	free(line);
	printf("%s",line = get_next_line(fd3));
	free(line);

	printf("%s",line = get_next_line(fd1));
	free(line);
	printf("%s",line = get_next_line(fd2));
	free(line);
	printf("%s",line = get_next_line(fd3));
	free(line);

	printf("%s",line = get_next_line(fd1));
	free(line);
	printf("%s",line = get_next_line(fd2));
	free(line);
	
	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
*/
