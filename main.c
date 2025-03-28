/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:29:50 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/28 00:43:50 by bel-abde         ###   ########.fr       */
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
	if (id == 13)
		move_up(game);
	else if (id == 1)
		move_down(game);
	else if (id == 2)
		move_right(game);
	else if (id == 0)
		move_left(game);
	else if (id == 53)
		close_window(game);
	printf("collectibles available: %d\n", game->collectibles);
	printf("collectibles earned: %d\n", game->collectibles_earned);
	return (0);
}

void	leaks()
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;

	// atexit(leaks);
	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			print_exit("ERROR: Wrong file extension.\n");
		parsing(&game, argv[1]);
		game.mlx = mlx_init();
		game.number_of_moves = 0;
		game.height = ft_arrlen(game.map) * 32;
		game.width = (ft_strlen(game.map[0])) * 32;
		game.mlx_window = mlx_new_window(game.mlx, game.width, \
			game.height, "so_long");
		xpm_to_img(&game);
		rendering(&game);
		mlx_hook(game.mlx_window, 2, 0, key_events, &game);
		mlx_hook(game.mlx_window, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
	}
	else
		printf("ERROR: Wrong number of arguments.\n");
	return (0);
}
