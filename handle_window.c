/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:55:53 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/30 16:45:53 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	mlx_initialization(t_map *map_data)
{
	t_mlx	mlx_data;

	mlx_data.mlx = mlx_init();
	mlx_data.window_height = map_data->map_size_y * SPRITE;
	mlx_data.window_lenght = map_data->map_size_x * SPRITE;
	mlx_data.window = mlx_new_window(mlx_data.mlx, mlx_data.window_lenght, \
	mlx_data.window_height, "so_long");
	import_all_sprites(mlx_data, map_data);
	return (mlx_data);
}

void	render_map(t_map map, t_mlx mlx_data)
{
	int	x;
	int	y;

	x = 0;
	mlx_clear_window(mlx_data.mlx, mlx_data.window);
	while (x < map.map_size_x)
	{
		y = 0;
		while (y < map.map_size_y)
		{
			render_sprite(&mlx_data, &map, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_data.mlx,mlx_data.window, \
	map.player_img, map.player_x * SPRITE, map.player_y * SPRITE);
}

int	close_game(t_mlx *data)
{
	destroy_mlx(data);
	free_data(data->map);
	return (0);	
}
