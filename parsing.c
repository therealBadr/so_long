/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:50:39 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 19:37:29 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_file(t_game *game, char *file_name)
{
	game->map_fd = open(file_name, O_RDONLY);
	if (game->map_fd == -1)
		print_exit("ERROR opening the file.\n");
	game->tmp = NULL;
}

static void	checks(t_game *game)
{
	is_rectangular(game);
	is_valid_char(game, "01PCE");
	walls_check(game, ft_arrlen(game->map), ft_strlen(game->map[0]));
	check_items_count(game);
	flood_fill(game, game->player_x, game->player_y);
	is_reachable(game);
}

void	parsing(t_game *game, char *file_name)
{
	char	*new_temp;

	open_file(game, file_name);
	game->gnl_holder = get_next_line(game->map_fd);
	if (!game->gnl_holder)
		print_exit_free(game, "Error\nEmpty file.\n");
	while (game->gnl_holder)
	{
		if (game->gnl_holder[0] == '\n')
			(free(game->gnl_holder), print_exit_free(game, "Error\n"));
		new_temp = ft_strjoin(game->tmp, game->gnl_holder);
		if (!new_temp)
			(free(game->gnl_holder), print_exit_free(game, "Error\n"));
		free(game->tmp);
		game->tmp = new_temp;
		free(game->gnl_holder);
		game->gnl_holder = get_next_line(game->map_fd);
	}
	if (!game->tmp)
        print_exit_free(game, "Error\nMap is empty");
	game->map = ft_split(game->tmp, '\n');
	game->map_copy = ft_split(game->tmp, '\n');
	free(game->tmp);
	game->tmp = NULL;
	checks(game);
}
