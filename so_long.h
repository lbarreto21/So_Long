/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:44:29 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/18 14:45:49 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

enum    e_errors {
    ARG_ERROR = -1,
    EXTENSION_ERROR = -2
};

typedef struct s_map {
    char    **map;
    int     map_size_x;
    int     map_size_y;
    int     collectables;
    int     player;
    int     exit;
    int     player_x;
    int     player_y;
    int     valid_collectables;
    int     valid_exit;
} t_map;

int     print_error(int error_code);
char    *open_map(char *file);
int     find_player_x(t_map data);
int     find_player_y(t_map data);
int     find_occurences(char *str, char c);
t_map	read_map(char *map);
void    flood_fill(t_map *map, int x, int y);

#endif
