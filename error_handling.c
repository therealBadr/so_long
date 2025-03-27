/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:32:45 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/26 22:06:45 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_exit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_exit_free(t_game *game, char *str)
{
	int	i;

	i = 0;
	// free_2d(game->map);
	// free_2d(game->map_copy);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	full_cleanup(game);
	exit(1);
}

void	invalid_img(t_game *game, void *img, char *str)
{
	int	i;

	i = 0;
	if (!img)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		close_window(game);
	}
}
