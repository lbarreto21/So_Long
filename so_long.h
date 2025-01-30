/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:44:29 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/30 16:52:38 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

#ifndef SPRITE
# define SPRITE 112
#endif

enum	e_keycodes {
	LEFT = 65361,
	UP = 65362,
	RIGHT = 65363,
	DOWN = 65364,
	A = 97,
	W = 119,
	S = 115,
	D = 100,
	ESC = 65307
};

enum    e_errors {
	ARG_ERROR = -1,
	EXTENSION_ERROR = -2,
	MAP_INVALID_CHARACTER_ERROR = -3,
	MAP_FORMAT_ERROR = -4,
	MAP_COMPONENTS_ERROR = -5,
	MAP_IS_NOT_CLOSED_ERROR = -6,
	MAP_COLLECTABLE_PATH_ERROR = -7,
	MAP_EXIT_PATH_ERROR = -8
};

typedef struct s_map {
	char	*map;
	char	**grid;
	int		map_size_x;
	int		map_size_y;
	int		collectables;
	int		player;
	int		exit;
	int		player_x;
	int		player_y;
	int		valid_collectables;
	int		valid_exit;
	int		movements_count;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*collectable_img;
	void	*exit_img;
} t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*window;
	int		window_height;
	int		window_lenght;
	t_map	*map;
} t_mlx;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

int		print_error(int error_code);
char	*open_map(char *file);
int		find_player_x(t_map data);
int		find_player_y(t_map data);
int		find_occurences(char *str, char c);
t_map	read_map(char *map);
void	flood_fill(t_map *data, char **map, int x, int y);
int		is_valid_character(char c);
int		verify_map_characters(char *map);
int		verify_map(t_map *data);
void	free_data(t_map *data);
int		verify_map_format(t_map *data);
int		verify_map_is_closed(t_map *data);
int		verify_map_path(t_map *data);
t_mlx	mlx_initialization(t_map *data);
void	*import_sprites(char *file_path, t_mlx *mlx_data);
void	import_all_sprites(t_mlx mlx_data, t_map *map_data);
void	render_sprite(t_mlx *mlx, t_map *map, int x, int y);
void	render_map(t_map map_data, t_mlx mlx_data);
int 	movement_player(int keycode, t_mlx *mlx);
void    moveplayer(char direction, t_map *map);
int		verify_and_move(char direction, t_map *map);
void	destroy_mlx(t_mlx *data);
int		close_game(t_mlx *data);
void	free_mlx(t_mlx *data);

#endif
