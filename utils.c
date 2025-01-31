/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:06:56 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/31 19:52:08 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(int error_code)
{
	ft_putstr_fd("ERROR: ", 2);
	if (error_code == ARG_ERROR)
		return (ft_putstr_fd("Wrong number of arguments.", 2), ARG_ERROR);
	if (error_code == EXTENSION_ERROR)
		return (ft_putstr_fd("Wrong extension of file.", 2), EXTENSION_ERROR);
	if (error_code == MAP_INVALID_CHARACTER_ERROR)
		return (ft_putstr_fd("Invalid character on map.", 2),
			MAP_INVALID_CHARACTER_ERROR);
	if (error_code == MAP_FORMAT_ERROR)
		return (ft_putstr_fd("Map is not a rectangle.", 2), MAP_FORMAT_ERROR);
	if (error_code == MAP_COMPONENTS_ERROR)
		return (ft_putstr_fd("Map must have at least 1 collectable and \
exactly 1 exit and 1 player", 2), MAP_COMPONENTS_ERROR);
	if (error_code == MAP_IS_NOT_CLOSED_ERROR)
		return (ft_putstr_fd("Map is not closed around by walls(1)", 2),
			MAP_IS_NOT_CLOSED_ERROR);
	if (error_code == MAP_COLLECTABLE_PATH_ERROR)
		return (ft_putstr_fd("There is a collectable without a valid path",
				2), MAP_COLLECTABLE_PATH_ERROR);
	if (error_code == MAP_EXIT_PATH_ERROR)
		return (ft_putstr_fd("There is not a valid path to the exit", 2),
			MAP_EXIT_PATH_ERROR);
	if (error_code == MAP_ERROR)
		return (ft_putstr_fd("Invalid map", 2), MAP_ERROR);
	return (-1);
}

int	find_occurences(char *str, char c)
{
	int	i;
	int	ocurrence;

	i = 0;
	ocurrence = 0;
	while (str[i])
	{
		if (str[i] == c)
			ocurrence++;
		i++;
	}
	return (ocurrence);
}

int	find_player_x(t_map data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.map_size_y)
	{
		j = 0;
		while (j < data.map_size_x)
		{
			if (data.grid[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_player_y(t_map data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.map_size_y)
	{
		j = 0;
		while (j < data.map_size_x)
		{
			if (data.grid[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(t_map *data, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_size_x || y >= data->map_size_y)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		data->valid_collectables++;
	else if (map[y][x] == 'E')
		data->valid_exit++;
	map[y][x] = 'X';
	flood_fill(data, map, x - 1, y);
	flood_fill(data, map, x + 1, y);
	flood_fill(data, map, x, y - 1);
	flood_fill(data, map, x, y + 1);
}
