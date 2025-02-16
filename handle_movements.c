/* ************************************************************************** */
/*    	                                                                      */
/*                                                        :::      ::::::::   */
/*   handle_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:05:58 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/29 20:31:32 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_player(int keycode, t_mlx *mlx)
{
	if (keycode == LEFT || keycode == A)
		moveplayer('A', mlx->map);
	if (keycode == RIGHT || keycode == D)
		moveplayer('D', mlx->map);
	if (keycode == UP || keycode == W)
		moveplayer('W', mlx->map);
	if (keycode == DOWN || keycode == S)
		moveplayer('S', mlx->map);
	if ((mlx->map->grid[mlx->map->player_y][mlx->map->player_x] == 'E' && \
	mlx->map->collectables == 0) || keycode == ESC)
		return (close_game(mlx));
	render_map(*mlx->map, *mlx);
	return (0);
}

void	moveplayer(char direction, t_map *map)
{
	if (verify_and_move(direction, map) == 1)
	{
		map->movements_count++;
		my_printf("Movements done: %d\n", map->movements_count);
	}
	if (map->grid[map->player_y][map->player_x] == 'C')
	{
		map->grid[map->player_y][map->player_x] = '0';
		map->collectables--;
	}
}

int	verify_and_move(char direction, t_map *map)
{
	if (direction == 'A')
	{
		if (map->grid[map->player_y][map->player_x - 1] != '1')
			return (map->player_x--, 1);
	}
	if (direction == 'D')
	{
		if (map->grid[map->player_y][map->player_x + 1] != '1')
			return (map->player_x++, 1);
	}
	if (direction == 'W')
	{
		if (map->grid[map->player_y - 1][map->player_x] != '1')
			return (map->player_y--, 1);
	}
	if (direction == 'S')
	{
		if (map->grid[map->player_y + 1][map->player_x] != '1')
			return (map->player_y++, 1);
	}
	return (0);
}
