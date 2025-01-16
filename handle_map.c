/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:19:18 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/16 15:20:09 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*open_map(char *file)
{
	int		fd;
	char	*map;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map = ft_strdup("");
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

t_map	read_map(char *map)
{
	t_map	data;
	int		i;

	i = 0;
	data.map = ft_strdup(map);
	data.grid = ft_split(map, '\n');
	data.map_size_x = ft_strlen(data.grid[0]);
	data.map_size_y = find_occurences(map, '\n') + 1;
	data.collectables = find_occurences(map, 'C');
	data.player = find_occurences(map, 'P');
	data.exit = find_occurences(map, 'E');
	data.player_x = find_player_x(data);
	data.player_y = find_player_y(data);
	data.valid_collectables = 0;
	data.valid_exit = 0;
	free(map);
	return (data);
}

int	verify_map(t_map *data)
{
	if (verify_map_characters(data->map) != 1)
		return (MAP_INVALID_CHARACTER_ERROR);
	if (verify_map_format(data) != 1)
		return (MAP_FORMAT_ERROR);
	if (verify_map_is_closed(data) != 1)
		return (MAP_IS_NOT_CLOSED_ERROR);
	if (data->collectables < 1 || data->exit != 1 || data->player != 1)
		return (MAP_COMPONENTS_ERROR);
	if (verify_map_path(data) != 1)
		return (verify_map_path(data));
	return (1);
}
