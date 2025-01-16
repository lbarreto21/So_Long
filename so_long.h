/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:44:29 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/16 15:18:48 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

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
} t_map;

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
void	free_data(t_map data);
int		verify_map_format(t_map *data);
int		verify_map_is_closed(t_map *data);
int		verify_map_path(t_map *data);

#endif
