/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:44:30 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 17:47:18 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	full_cleanup(t_game *game)
{
	if (game->mlx)
	{
		if (game->collec_img)
			mlx_destroy_image(game->mlx, game->collec_img);
		if (game->floor_img)
			mlx_destroy_image(game->mlx, game->floor_img);
		if (game->player_img)
			mlx_destroy_image(game->mlx, game->player_img);
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
		if (game->mlx_window)
			mlx_destroy_window(game->mlx, game->mlx_window);
	}
	free_2d(game->map);
	free_2d(game->map_copy);
	if (game->tmp)
		free(game->tmp);
	if (game->gnl_holder)
		free(game->gnl_holder);
}

void	destroy_images(t_game *game)
{
	if (game->collec_img)
		mlx_destroy_image(game->mlx, game->collec_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
}

int	close_window(t_game *game)
{
	full_cleanup(game);
	exit(0);
	return (0);
}
