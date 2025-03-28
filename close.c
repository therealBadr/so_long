/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:44:30 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 22:00:00 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void safe_free(void **ptr)
{
    if (*ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

// void full_cleanup(t_game *game)
// {
//     runtime_cleanup(game);
// }

void parsing_cleanup(t_game *game)
{
    if (!game) return;
    
    free_2d(game->map);
    free_2d(game->map_copy);
    if (game->tmp) free(game->tmp);
    if (game->gnl_holder) free(game->gnl_holder);
    
    // Explicitly NULL all pointers
    game->map = NULL;
    game->map_copy = NULL;
    game->tmp = NULL;
    game->gnl_holder = NULL;
}

void	full_cleanup(t_game *game)
{
	// Cleanup MLX resources if MLX was initialized
	if (game->mlx)
	{
		// Destroy images (order doesn't matter for images)
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
		
		// Destroy window last (must come after destroying its images)
		if (game->mlx_window)
			mlx_destroy_window(game->mlx, game->mlx_window);
		
		// Note: We don't destroy the mlx pointer itself
	}
	
	// Free maps
	if (game->map)
		free_2d(game->map);
	if (game->map_copy)
		free_2d(game->map_copy);
	
	// Free temporary strings
	if (game->tmp)
	{
		free(game->tmp);
		game->tmp = NULL;
	}
	if (game->gnl_holder)
	{
		free(game->gnl_holder);
		game->gnl_holder = NULL;
	}
	
	// Optional: Close file descriptor if still open
	if (game->map_fd != -1)
	{
		close(game->map_fd);
		game->map_fd = -1;
	}
}

// void	full_cleanup(t_game *game)
// {
// 	if (game->mlx)
// 	{
// 		if (game->collec_img)
// 			mlx_destroy_image(game->mlx, game->collec_img);
// 		if (game->floor_img)
// 			mlx_destroy_image(game->mlx, game->floor_img);
// 		if (game->player_img)
// 			mlx_destroy_image(game->mlx, game->player_img);
// 		if (game->wall_img)
// 			mlx_destroy_image(game->mlx, game->wall_img);
// 		if (game->exit_img)
// 			mlx_destroy_image(game->mlx, game->exit_img);
// 		if (game->mlx_window)
// 			mlx_destroy_window(game->mlx, game->mlx_window);
// 	}
// 	free_2d(game->map);
// 	free_2d(game->map_copy);
// 	if (game->tmp)
// 		free(game->tmp);
// 	if (game->gnl_holder)
// 		free(game->gnl_holder);
// }

void runtime_cleanup(t_game *game)
{
    if (!game) return;
    
    if (game->mlx)
    {
        destroy_images(game);
        if (game->mlx_window)
            mlx_destroy_window(game->mlx, game->mlx_window);
    }
    
    parsing_cleanup(game); // Also clean parsing data
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

int close_window(t_game *game)
{
    full_cleanup(game);
    exit(0);
    return (0);
}
