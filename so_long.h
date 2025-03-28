/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:30:57 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/28 00:28:15 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include <stdio.h>
# include "MLX/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_game
{
	int			map_fd;
	char		*tmp;
	char		**map;
	char		**map_copy;
	int			collectibles;
	int			collectibles_earned;
	int			player;
	int			exit;
	int			player_x;
	int			player_y;
	int			width;
	int			height;
	void		*mlx;
	void		*mlx_window;
	int			movements;
	int			exit_x;
	int			exit_y;
	char		*gnl_holder;
	void		*wall_img;
	void		*collec_img;
	void		*player_img;
	void		*exit_img;
	void		*floor_img;
	int			number_of_moves;
} t_game;


//utils
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_arrlen(char **str);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strchr(char *str, int c);
void	*ft_calloc(size_t count, size_t size);
void	free_all(char *stash, char *buffer);
char	*get_my_line(char *stash, int i);
char	*modify_stash(char *stash, int i);
char	*get_next_line(int fd);
char    **ft_split(char const *s, char c);
int		belongs_to_set(char *set, char c);

// error handling
void	print_exit(char *str);
void	free_2d(char **str);
void	print_exit_free(t_game *game, char *str);
void	invalid_img(t_game *game, void *img, char *str);

// parsing
void	parsing(t_game *game, char *file_name);
void	is_rectangular(t_game *game);
void	is_valid_char(t_game *game, char *set);
void	walls_check(t_game *game, int arr_len, int str_len);
void	initialize_items(t_game *game);
void	check_items_count(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	is_reachable(t_game *game);

int	close_window(t_game *game);

// rendering
void	xpm_to_img(t_game *game);
void	img_to_window(t_game *game, int i, int j);
void	rendering(t_game *game);

// moves
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	update_player_up(t_game *game);
void	update_player_down(t_game *game);
void	update_player_left(t_game *game);
void	update_player_right(t_game *game);

int	key_events(int id, t_game *game);
void	destroy_images(t_game *game);
void full_cleanup(t_game *game);

void safe_free(void **ptr);
void parsing_cleanup(t_game *game);
void runtime_cleanup(t_game *game);
void	free_parsing(t_game *game, char *str);

void	open_file(t_game *game, char *file_name);
void	handle_empty_file(t_game *game);
void	process_gnl_line(t_game *game, char **new_temp);
void	process_map_content(t_game *game);
void	create_map_arrays(t_game *game);

#endif