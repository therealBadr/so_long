/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:15:16 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/28 00:26:08 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_file(t_game *game, char *file_name)
{
	game->map_fd = open(file_name, O_RDONLY);
	if (game->map_fd == -1)
		print_exit("ERROR opening the file.\n");
	game->tmp = NULL;
	game->gnl_holder = NULL;
}

void	handle_empty_file(t_game *game)
{
	close(game->map_fd);
	print_exit("Error\nEmpty file\n");
}

void	process_gnl_line(t_game *game, char **new_temp)
{
	if (game->tmp)
		*new_temp = ft_strjoin(game->tmp, game->gnl_holder);
	else
		*new_temp = ft_strdup(game->gnl_holder);
	if (!*new_temp)
	{
		free(game->gnl_holder);
		free(game->tmp);
		close(game->map_fd);
		print_exit("Error\nMemory allocation failed");
	}
}

void	process_map_content(t_game *game)
{
	char	*new_temp;

	while (game->gnl_holder)
	{
		if (game->gnl_holder[0] == '\n' && game->gnl_holder[1] == '\0')
		{
			free(game->gnl_holder);
			free(game->tmp);
			close(game->map_fd);
			print_exit("Error\nEmpty line in map");
		}
		process_gnl_line(game, &new_temp);
		free(game->tmp);
		game->tmp = new_temp;
		free(game->gnl_holder);
		game->gnl_holder = get_next_line(game->map_fd);
	}
}

void	create_map_arrays(t_game *game)
{
	if (!game->tmp || game->tmp[0] == '\0')
	{
		free(game->tmp);
		close(game->map_fd);
		print_exit("Error\nMap is empty");
	}
	game->map = ft_split(game->tmp, '\n');
	game->map_copy = ft_split(game->tmp, '\n');
	free(game->tmp);
	game->tmp = NULL;
	if (!game->map || !game->map_copy)
	{
		if (game->map)
			free_2d(game->map);
		if (game->map_copy)
			free_2d(game->map_copy);
		close(game->map_fd);
		print_exit("Error\nMap allocation failed");
	}
}
