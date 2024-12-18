/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:19:18 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/18 15:01:25 by lbarreto         ###   ########.fr       */
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
	return (map);
}

t_map	read_map(char *map)
{
	t_map data;
	
	data.map = ft_split(map, '\n');
	data.map_size_y = ft_strlen(data.map[0]);
	data.map_size_x = find_occurences(map, '\n') + 1;
	data.collectables = find_occurences(map, 'C');
	data.player = find_occurences(map, 'P');
	data.exit = find_occurences(map, 'E');
	data.player_x = find_player_x(data);
	data.player_y = find_player_y(data);
	data.valid_collectables = 0;
	data.valid_exit = 0;
	flood_fill(&data, data.player_x, data.player_y);

	return (data);
}