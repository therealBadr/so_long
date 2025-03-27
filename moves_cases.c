/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:53:10 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/20 13:52:06 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
		 game->player_x * 32, game->player_y * 32);
	game->player_y--;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
		game->player_x * 32, game->player_y * 32);
}

void	update_player_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
		 game->player_x * 32, game->player_y * 32);
	game->player_y++;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
		game->player_x * 32, game->player_y * 32);
}

void	update_player_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
		 game->player_x * 32, game->player_y * 32);
	game->player_x--;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
		game->player_x * 32, game->player_y * 32);
}

void	update_player_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
		 game->player_x * 32, game->player_y * 32);
	game->player_x++;
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
		game->player_x * 32, game->player_y * 32);
}

// void update_player_up(t_game *game)
// {
//     // Clear old player position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
//         game->player_x * 32, game->player_y * 32);

//     // Update player position
//     game->player_y--;

//     // Render player at new position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
//         game->player_x * 32, game->player_y * 32);
// }

// void update_player_down(t_game *game)
// {
//     // Clear old player position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
//         game->player_x * 32, game->player_y * 32);

//     // Update player position
//     game->player_y++;

//     // Render player at new position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
//         game->player_x * 32, game->player_y * 32);
// }

// void update_player_left(t_game *game)
// {
//     // Clear old player position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
//         game->player_x * 32, game->player_y * 32);

//     // Update player position
//     game->player_x--;

//     // Render player at new position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
//         game->player_x * 32, game->player_y * 32);
// }

// void update_player_right(t_game *game)
// {
//     // Clear old player position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->floor_img,
//         game->player_x * 32, game->player_y * 32);

//     // Update player position
//     game->player_x++;

//     // Render player at new position
//     mlx_put_image_to_window(game->mlx, game->mlx_window, game->player_img,
//         game->player_x * 32, game->player_y * 32);
// }
