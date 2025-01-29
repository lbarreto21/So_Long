/* ************************************************************************** */
/*    	                                                                        */
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

int movement_player(int keycode, t_map *map, t_mlx *mlx)
{
	if (keycode == LEFT || keycode == A)
		moveplayer('A', map);
	if (keycode == RIGHT || keycode == D)
		moveplayer('D', map);
	if (keycode == UP || keycode == W)
		moveplayer('W', map);
	if (keycode == DOWN || keycode == S)
        moveplayer('S', map);
	return (0);
}

void	  	moveplayer(char direction, t_map *map)
{
	if (direction == 'A')
	{
		if (map->grid[map->player_x][map->player_y - 1] != '1')
			map->player_y--;
	}
	if (direction == 'D')
	{
		if (map->grid[map->player_x][map->player_y + 1] != '1')
			map->player_y++;
	}
	if (direction == 'W')
	{
		if (map->grid[map->player_x + 1][map->player_y] != '1')
			map->player_x++;
	}
	if (direction == 'S')
	{
		if (map->grid[map->player_x - 1][map->player_y] != '1')
			map->player_x--;
	}
	if (map->grid[map->player_x][map->player] == 'C')
	{
		map->grid[map->player_x][map->player] = '0';
		map->collectables--;
	}
}