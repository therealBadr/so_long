/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:09:04 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/26 22:06:17 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void full_cleanup(t_game *game)
{
    // Free images first (before destroying display)
    if (game->mlx) {
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
        
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }

    // Free map data
    free_2d(game->map);
    free_2d(game->map_copy);
    
    // Free temporary strings
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
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit_img);
}

int	close_window(t_game *game)
{
	// destroy_images(game);
	// if (game->mlx_window)
	// 	mlx_destroy_window(game->mlx, game->mlx_window);
	// free_2d(game->map);
	// free_2d(game->map_copy);
	full_cleanup(game);
	exit(0);
	return (0);
}

void	xpm_to_img(t_game *game)
{
	int	i;
	int	j;

	game->floor_img = mlx_xpm_file_to_image(game->mlx,
		"assets/floor_32.xpm", &i, &j);
	invalid_img(game, game->floor_img, \
		"Invalid floor_img.xpm file\n");
		
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"assets/player_32.xpm", &i, &j);
			
	invalid_img(game, game->player_img, \
		"Invalid player_img.xpm file\n");
		
	game->collec_img = mlx_xpm_file_to_image(game->mlx, \
		"assets/col_32.xpm", &i, &j);

	invalid_img(game, game->collec_img, \
		"Invalid col_img.xpm file\n");
		
	game->exit_img = mlx_xpm_file_to_image(game->mlx, \
		"assets/exit_32.xpm", &i, &j);

	invalid_img(game, game->exit_img, \
		"Invalid exit_open.xpm file\n");
		
	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
		"assets/wall_32.xpm", &i, &j);
		
	invalid_img(game, game->wall_img, \
		"Invalid wall_img.xpm file\n");
}

void	img_to_window(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
	game->wall_img, j * 32, i * 32);
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
	game->collec_img, j * 32, i * 32);
	}
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
			game->player_img, j * 32, i * 32);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
			game->exit_img, j * 32, i * 32);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_window, \
			game->floor_img, j * 32, i * 32);
}

void	rendering(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			img_to_window(game, i, j);
			j++;
		}
		i++;
	}
}
