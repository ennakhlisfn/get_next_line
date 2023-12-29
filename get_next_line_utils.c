/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:00:08 by sennakhl          #+#    #+#             */
/*   Updated: 2023/12/27 09:25:54 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*tab;

	i = 0;
	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	while (i < count * size)
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (dst != NULL || src != NULL))
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
