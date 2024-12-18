/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:47 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/18 14:56:10 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*file_extension;
	char	*map;
	t_map	data;

	if (argc != 2)
		return (print_error(ARG_ERROR));
	file_extension = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (!file_extension)
		return (print_error(EXTENSION_ERROR));
	map = open_map(argv[1]);
	data = read_map(map);
	printf("mapa:\n%s\n", map);
	printf("Map size x: %d\nMap size y: %d\ncollectables: %d\nplayer: %d\nexit: %d\nplayer x: %d\nplayer y: %d\nFirst line: %s", data.map_size_x, data.map_size_y, data.collectables, data.player, data.exit, data.player_x, data.player_y, data.map[4]);
	free(map);
	return (0);
}
