/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:52:34 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 17:43:35 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangular(t_game *game)
{
	int	i;
	int	line;

	i = 0;
	line = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != line)
			print_exit_free(game, "ERROR: Map must be rectangular.\n");
		i++;
	}
}

void	is_valid_char(t_game *game, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!belongs_to_set(set, game->map[i][j]))
			{
				print_exit_free(game, "ERROR: Invalid chars.\n");
			}
			j++;
		}
		i++;
	}
}

void	walls_check(t_game *game, int arr_len, int str_len)
{
	char	*first_line;
	char	*last_line;
	int		i;

	i = 0;
	first_line = game->map[i];
	last_line = game->map[arr_len - 1];
	while (first_line[i])
	{
		if (first_line[i] != '1' || last_line[i] != '1')
		{
			print_exit_free(game, "ERROR: Map must be surrounded by walls.\n");
		}
		i++;
	}
	i = 1;
	while (game->map[i] && i < arr_len - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][str_len - 1] != '1')
			print_exit_free(game, "ERROR: Map must be surrounded by walls.\n");
		i++;
	}
}

void	initialize_items(t_game *game)
{
	int	i;
	int	j;

	game->collectibles = 0;
	game->collectibles_earned = 0;
	game->player = 0;
	game->exit = 0;
	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_items_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	initialize_items(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'P')
				game->player++;
			j++;
		}
		i++;
	}
	if (game->collectibles < 1 || game->exit != 1 || game->player != 1)
		print_exit_free(game, "ERROR: Wrong items count.\n");
}
