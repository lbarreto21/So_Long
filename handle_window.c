/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:55:53 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/29 19:09:40 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	mlx_initialization(t_map *map_data)
{
	t_mlx	mlx_data;

	mlx_data.mlx = mlx_init();
	mlx_data.window_height = map_data->map_size_y * IMAGE_PROPORTION;
	mlx_data.window_lenght = map_data->map_size_x * IMAGE_PROPORTION;
	mlx_data.window = mlx_new_window(mlx_data.mlx, mlx_data.window_lenght, \
	mlx_data.window_height, "so_long");
	import_all_sprites(mlx_data, map_data);
	return (mlx_data);	
}

void	render_map(t_map map_data, t_mlx mlx_data)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_data.map_size_x)
	{
		y = 0;
		while (y < map_data.map_size_y)
		{
			if (map_data.grid[x][y] == '1')
				mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, \
				map_data.wall_img, x * IMAGE_PROPORTION, y * IMAGE_PROPORTION);
			if (map_data.grid[x][y] == '0')
				mlx_put
				
		}
	}
}