/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:33 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/26 21:36:46 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		// printf("Moving up\n");
		// printf("collectibles to earn: %d\n", game->collectibles);
		// printf("collectibles_count: %d\n", game->collectibles_count);
		if (game->map[game->player_y - 1][game->player_x] == 'C')
		{
			game->collectibles_count++;
			game->map[game->player_y - 1][game->player_x] = '0';
			update_player_up(game);
		}
		else if (game->map[game->player_y - 1][game->player_x] == 'E')
		{
			if (game->collectibles == game->collectibles_count)
			{
				write(1, "You win.\n", 9);
				close_window(game);
			}		
		}
		else
			update_player_up(game);
	}
}

// void move_up(t_game *game)
// {
//     int new_y = game->player_y - 1;
//     int new_x = game->player_x;

//     printf("Current player position: (%d, %d)\n", game->player_x, game->player_y);
//     printf("Attempting to move to: (%d, %d)\n", new_x, new_y);

//     if (new_y >= 0 && game->map[new_y][new_x] != '1') // Check if target is within bounds and not a wall
//     {
//         if (game->map[new_y][new_x] == 'C') // Check if target is a collectible
//         {
//             game->collectibles_count++;
//             game->map[new_y][new_x] = '0'; // Remove collectible from map
//         }
//         else if (game->map[new_y][new_x] == 'E') // Check if target is exit
//         {
//             if (game->collectibles == game->collectibles_count)
//             {
//                 write(1, "You win.\n", 9);
//                 close_window(game);
//                 return;
//             }
//         }

//         // Update player position
//         game->player_y = new_y;

//         // Re-render the map
//         rendering(game);
//     }
//     else
//     {
//         printf("Invalid move: Out of bounds or wall.\n");
//     }
// }

void	move_down(t_game *game)
{
	if (game->player_y + 1 >= game->height)
        return;
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		// printf("collectibles to earn: %d\n", game->collectibles);
		// printf("collectibles_count: %d\n", game->collectibles_count);
		if (game->map[game->player_y + 1][game->player_x] == 'C')
		{
			game->collectibles_count++;
			game->map[game->player_y + 1][game->player_x] = '0';
			update_player_down(game);
		}
		else if (game->map[game->player_y + 1][game->player_x] == 'E')
		{
			if (game->collectibles == game->collectibles_count)
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
		// printf("collectibles to earn: %d\n", game->collectibles);
		// printf("collectibles_count: %d\n", game->collectibles_count);
		if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			game->collectibles_count++;
			game->map[game->player_y][game->player_x - 1] = '0';
			update_player_left(game);
		}
		else if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			if (game->collectibles == game->collectibles_count)
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
		// printf("collectibles to earn: %d\n", game->collectibles);
		// printf("collectibles_count: %d\n", game->collectibles_count);
		if (game->map[game->player_y][game->player_x + 1] == 'C')
		{
			game->collectibles_count++;
			game->map[game->player_y][game->player_x + 1] = '0';
			update_player_right(game);
		}
		else if (game->map[game->player_y][game->player_x + 1] == 'C')
		{
			if (game->collectibles == game->collectibles_count)
			{
				write(1, "You win.\n", 9);
				close_window(game);
			}
		}
		else
			update_player_right(game);
	}
}


// void move_up(t_game *game)
// {
//     if (game->map[game->player_y - 1][game->player_x] != '1') // Check if target is not a wall
//     {
//         if (game->map[game->player_y - 1][game->player_x] == 'C') // Check if target is a collectible
//         {
//             game->collectibles_count++;
//             game->map[game->player_y - 1][game->player_x] = '0'; // Remove collectible
//             update_player_up(game);
//         }
//         else if (game->map[game->player_y - 1][game->player_x] == 'E') // Check if target is exit
//         {
//             if (game->collectibles == game->collectibles_count) // Check if all collectibles are collected
//             {
//                 write(1, "You win.\n", 9);
//                 close_window(game);
//             }
//         }
//         else
//             update_player_up(game);
//     }
// }

// void move_down(t_game *game)
// {
//     if (game->map[game->player_y + 1][game->player_x] != '1') // Check if target is not a wall
//     {
//         if (game->map[game->player_y + 1][game->player_x] == 'C') // Check if target is a collectible
//         {
//             game->collectibles_count++;
//             game->map[game->player_y + 1][game->player_x] = '0'; // Remove collectible
//             update_player_down(game);
//         }
//         else if (game->map[game->player_y + 1][game->player_x] == 'E') // Check if target is exit
//         {
//             if (game->collectibles == game->collectibles_count) // Check if all collectibles are collected
//             {
//                 write(1, "You win.\n", 9);
//                 close_window(game);
//             }
//         }
//         else
//             update_player_down(game);
//     }
// }

// void move_left(t_game *game)
// {
//     if (game->map[game->player_y][game->player_x - 1] != '1') // Check if target is not a wall
//     {
//         if (game->map[game->player_y][game->player_x - 1] == 'C') // Check if target is a collectible
//         {
//             game->collectibles_count++;
//             game->map[game->player_y][game->player_x - 1] = '0'; // Remove collectible
//             update_player_left(game);
//         }
//         else if (game->map[game->player_y][game->player_x - 1] == 'E') // Check if target is exit
//         {
//             if (game->collectibles == game->collectibles_count) // Check if all collectibles are collected
//             {
//                 write(1, "You win.\n", 9);
//                 close_window(game);
//             }
//         }
//         else
//             update_player_left(game);
//     }
// }

// void move_right(t_game *game)
// {
//     if (game->map[game->player_y][game->player_x + 1] != '1') // Check if target is not a wall
//     {
//         if (game->map[game->player_y][game->player_x + 1] == 'C') // Check if target is a collectible
//         {
//             game->collectibles_count++;
//             game->map[game->player_y][game->player_x + 1] = '0'; // Remove collectible
//             update_player_right(game);
//         }
//         else if (game->map[game->player_y][game->player_x + 1] == 'E') // Check if target is exit
//         {
//             if (game->collectibles == game->collectibles_count) // Check if all collectibles are collected
//             {
//                 write(1, "You win.\n", 9);
//                 close_window(game);
//             }
//         }
//         else
//             update_player_right(game);
//     }
// }