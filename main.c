/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:47 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/29 16:26:48 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*file_extension;
	char	*map;
	t_map	data;
	int		verification;
	t_mlx	mlx_data;

	if (argc != 2)
		return (print_error(ARG_ERROR));
	file_extension = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (!file_extension)
		return (print_error(EXTENSION_ERROR));
	map = open_map(argv[1]);
	data = read_map(map);
	verification = verify_map(&data);
	if (verification < 0)
	{
		free_data(data);
		return (print_error(verification));
	}
	create_window(data);
	printf("mapa: \n%s\n", data.map);
	printf("Map size x: %d\nMap size y: %d\ncollectables: %d\nplayer: %d\nexit: %d\nplayer x: %d\nplayer y: %d\nvalid collectables: %d\nvalid exits: %d\n", data.map_size_x, data.map_size_y, data.collectables, data.player, data.exit, data.player_x, data.player_y, data.valid_collectables, data.valid_exit);
	free_data(data);
	return (0);
}
