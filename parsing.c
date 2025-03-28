/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:50:39 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/28 01:14:51 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void checks(t_game *game)
{
    // 1. Check component counts first (fastest failure)
    check_items_count(game);
    
    // 2. Validate characters before structural checks
    is_valid_char(game, "01PCE");
    
    // 3. Check map structure
    is_rectangular(game);
    walls_check(game, ft_arrlen(game->map), ft_strlen(game->map[0]));
    
    // 4. Path validation (only if above checks pass)
    flood_fill(game, game->player_x, game->player_y);
    is_reachable(game);
}

void	parsing(t_game *game, char *file_name)
{
	open_file(game, file_name);
	game->gnl_holder = get_next_line(game->map_fd);
	if (!game->gnl_holder)
		handle_empty_file(game);
	game->tmp = NULL;
	process_map_content(game);
	create_map_arrays(game);
	close(game->map_fd);
	checks(game);
}
