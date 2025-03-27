/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:16:28 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/15 23:16:39 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
}

char	*read_line(int fd, char *stash, int bytes_read)
{
	char	*buffer;
	char	*old_stash;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	while ((bytes_read != 0) && (!ft_strchr(stash, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_all(stash, buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		old_stash = stash;
		stash = ft_strjoin(stash, buffer);
		free(old_stash);
	}
	free(buffer);
	return (stash);
}

char	*get_my_line(char *stash, int i)
{
	char	*line;
	int		length;

	length = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		i++;
		length++;
	}
	if (stash[i] == '\n')
		length++;
	line = ft_calloc((length + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < length)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*modify_stash(char *stash, int i)
{
	char	*new;
	int		index;

	index = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new = malloc((ft_strlen(stash) - i) + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i])
		new[index++] = stash[i++];
	new[index] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			bytes_read;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	bytes_read = 1;
	i = 0;
	stash = read_line(fd, stash, bytes_read);
	if (!stash)
		return (NULL);
	line = get_my_line(stash, i);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = modify_stash(stash, i);
	return (line);
}