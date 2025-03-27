/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:42:28 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 18:31:33 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	char	pos;

	if (x < 0 || y < 0 || x >= ft_strlen(game->map[0]) || \
		y >= ft_arrlen(game->map))
		return ;
	pos = game->map_copy[y][x];
	if (pos == '1' || pos == 'X')
		return ;
	if (pos == 'E')
    {
        game->map_copy[y][x] = 'X';
        return;
    }
	game->map_copy[y][x] = 'X';
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
	flood_fill(game, x - 1, y);
}

void	is_reachable(t_game *game)
{
	int	i;
	int	j;
	int	collectibles;
	int	exit;

	i = 0;
	collectibles = 0;
	exit = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'C')
				collectibles++;
			else if (game->map_copy[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit > 0 || collectibles > 0)
		print_exit_free(game, "ERROR: All elements must be reachable.\n");
}
