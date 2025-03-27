/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:16:54 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 17:48:24 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!stash)
		return (ft_strdup(buffer));
	ptr = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!ptr)
		return (NULL);
	while (stash[i])
	{
		ptr[i] = stash[i];
		i++;
	}
	while (buffer[j])
	{
		ptr[i] = buffer[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] || (char)c == '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			l;

	i = 0;
	l = count * size ;
	if (size && count != (l / size))
		return (NULL);
	ptr = malloc(l);
	if (!ptr)
		return (NULL);
	while (i < l)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*ptr;

	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
