/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:06:56 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/15 14:58:34 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(int error_code)
{
	ft_putstr_fd("ERROR: ", 2);
	if (error_code == ARG_ERROR)
		return (ft_putstr_fd("Wrong number of arguments", 2), ARG_ERROR);
	if (error_code == EXTENSION_ERROR)
		return (ft_putstr_fd("Wrong extension of file", 2), EXTENSION_ERROR);
	if (error_code == MAP_INVALID_CHARACTER_ERROR)
		return (ft_putstr_fd("Invalid character on map", 2),
			MAP_INVALID_CHARACTER_ERROR);
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
	while (i < data.map_size_x)
	{
		j = 0;
		while (j < data.map_size_y)
		{
			if (data.grid[i][j] == 'P')
				return (i);
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
	while (i < data.map_size_x)
	{
		j = 0;
		while (j < data.map_size_y)
		{
			if (data.grid[i][j] == 'P')
				return (j);
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
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	if (map[x][y] == 'C')
		data->valid_collectables++;
	else if (map[x][y] == 'E')
		data->valid_exit++;
	map[x][y] = 'X';
	flood_fill(data, map, x - 1, y);
	flood_fill(data, map, x + 1, y);
	flood_fill(data, map, x, y - 1);
	flood_fill(data, map, x, y + 1);
}
