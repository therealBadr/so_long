/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:33 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 17:40:05 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
		{
			game->collectibles_earned++;
			game->map[game->player_y - 1][game->player_x] = '0';
			update_player_up(game);
		}
		else if (game->map[game->player_y - 1][game->player_x] == 'E')
		{
			if (game->collectibles == game->collectibles_earned)
			{
				write(1, "You win.\n", 9);
				close_window(game);
			}
		}
		else
			update_player_up(game);
	}
}

void	move_down(t_game *game)
{
	if (game->player_y + 1 >= game->height)
		return ;
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
		{
			game->collectibles_earned++;
			game->map[game->player_y + 1][game->player_x] = '0';
			update_player_down(game);
		}
		else if (game->map[game->player_y + 1][game->player_x] == 'E')
		{
			if (game->collectibles == game->collectibles_earned)
			{
				write(1, "You win.\n", 9);
				close_window(game);
			}
		}
		else
			update_player_down(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			game->collectibles_earned++;
			game->map[game->player_y][game->player_x - 1] = '0';
			update_player_left(game);
		}
		else if (game->map[game->player_y][game->player_x - 1] == 'E')
		{
			if (game->collectibles == game->collectibles_earned)
			{
				write(1, "You win.\n", 9);
				close_window(game);
			}
		}
		else
			update_player_left(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
		{
			game->collectibles_earned++;
			game->map[game->player_y][game->player_x + 1] = '0';
			update_player_right(game);
		}
		else if (game->map[game->player_y][game->player_x + 1] == 'E')
		{
			if (game->collectibles == game->collectibles_earned)
			{
				write(1, "You win.\n", 9);
				close_window(game);
			}
		}
		else
			update_player_right(game);
	}
}
