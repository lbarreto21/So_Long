/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:50 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/29 19:41:25 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_map_characters(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_valid_character(map[i]) == 0)
			return (MAP_INVALID_CHARACTER_ERROR);
		i++;
	}
	return (1);
}

int	verify_map_format(t_map *data)
{
	int	i;

	i = 1;
	while (i < data->map_size_y)
	{
		if (ft_strlen(data->grid[0]) != ft_strlen(data->grid[i]))
			return (MAP_FORMAT_ERROR);
		i++;
	}
	return (1);
}

int	verify_map_is_closed(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->map_size_x)
	{
		if (data->grid[0][i] != '1' ||
		data->grid[data->map_size_y - 1][i] != '1')
			return (MAP_IS_NOT_CLOSED_ERROR);
		i++;
	}
	i = 0;
	while (i < data->map_size_y)
	{
		if (data->grid[i][0] != '1' ||
		data->grid[i][data->map_size_x - 1] != '1')
			return (MAP_IS_NOT_CLOSED_ERROR);
		i++;
	}
	return (1);
}

int	verify_map_path(t_map *data)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_split(data->map, '\n');
	flood_fill(data, grid, data->player_x, data->player_y);
	while (i < data->map_size_y)
		free(grid[i++]);
	free(grid);
	if (data->collectables != data->valid_collectables)
		return (MAP_COLLECTABLE_PATH_ERROR);
	if (data->exit != data->valid_exit)
		return (MAP_EXIT_PATH_ERROR);
	return (1);
}
