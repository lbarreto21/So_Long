/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:46:54 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/31 16:47:33 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*import_sprites(char *file_path, t_mlx *mlx_data)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(mlx_data->mlx, file_path, &img_w, &img_h);
	return (img);
}

void	import_all_sprites(t_mlx mlx_data, t_map *map_data)
{
	map_data->player_img = import_sprites("assets/Character.xpm", &mlx_data);
	map_data->wall_img = import_sprites("assets/Wall.xpm", &mlx_data);
	map_data->floor_img = import_sprites("assets/Floor.xpm", &mlx_data);
	map_data->collectable_img = import_sprites("assets/Collectable.xpm", \
	&mlx_data);
	map_data->exit_img = import_sprites("assets/Exit.xpm", &mlx_data);
}

void	render_sprite(t_mlx *mlx, t_map *map, int x, int y)
{
	if (map->grid[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->wall_img, x * SPRITE, y * SPRITE);
	if (map->grid[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->floor_img, x * SPRITE, y * SPRITE);
	if (map->grid[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->floor_img, x * SPRITE, y * SPRITE);
	if (map->grid[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->collectable_img, x * SPRITE, y * SPRITE);
	if (map->grid[y][x] == 'E' && map->collectables == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->exit_img, x * SPRITE, y * SPRITE);
	else if (map->grid[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->floor_img, x * SPRITE, y * SPRITE);
}
