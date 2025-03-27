/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:29:50 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/22 23:01:34 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_extension(char *str)
{
	char	*start;

	start = &str[ft_strlen(str) - 4];
	if (ft_strcmp(start, ".ber") == 0)
		return (1);
	return (0);
}

int	key_events(int id, t_game *game)
{
	// printf("Key pressed: %d\n", id);
	if (id == 119)
		move_up(game);
	else if (id == 115)
		move_down(game);
	else if (id == 100)
		move_right(game);
	else if (id == 97)
		move_left(game);	
	else if (id == 65307)
		close_window(game);
	return (0);
}

// int key_events(int id, t_game *game)
// {
// 	(void)game;
//     printf("Key pressed: %d\n", id); // Debug print

//     // Test all key presses
//     if (id == 119) // W key
//         printf("W key pressed.\n");
//     else if (id == 115) // S key
//         printf("S key pressed.\n");
//     else if (id == 100) // D key
//         printf("D key pressed.\n");
//     else if (id == 97) // A key
//         printf("A key pressed.\n");
//     else if (id == 53) // ESC key
//         printf("ESC key pressed.\n");

//     return (0);
// }

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			print_exit("Error\n");
		parsing(&game, argv[1]);
		game.mlx = mlx_init();
		game.height = ft_arrlen(game.map) * 32;
		game.width = (ft_strlen(game.map[0])) * 32;
		// printf("Map width: %d\n", game.width);
		// printf("Map height: %d\n", game.height);
		// for (int i = 0; i < ft_arrlen(game.map); i++)
		// 	printf("%s\n", game.map[i]);
		game.mlx_window = mlx_new_window(game.mlx, game.width, game.height, "so_long");
		xpm_to_img(&game);
		rendering(&game);
		// printf("Rendering done.\n");
		// printf("Player x=%d , y=%d \n", game.player_x, game.player_y);
		// printf("Map:  %c \n", game.map[3][1]);
		mlx_hook(game.mlx_window, 2, 1L << 0, key_events, &game);
		// printf("Key events hook registered.\n");
		mlx_hook(game.mlx_window, 17, 0, close_window, &game);
		// printf("Starting event loop...\n");
		mlx_loop(game.mlx);
	}
	else
		printf("Error.\n");
	return (0);
}

// w = 119
// s = 115
// d = 100
// a = 97