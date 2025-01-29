/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:55:53 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/29 16:30:47 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	mlx_initialization(t_map data)
{
	t_mlx	mlx_data;

	mlx_data.mlx = mlx_init();
	mlx_data.window_height = data.map_size_y * IMAGE_PROPORTION;
	mlx_data.window_lenght = data.map_size_x * IMAGE_PROPORTION;
	mlx_data.window = mlx_new_window(mlx_data.mlx, mlx_data.window_lenght, \
	mlx_data.window_height, "so_long");

	return (mlx_data);	
}

void	create_window(t_map data)
{
	t_mlx	mlx_data;
	t_img	img;
	int		size;
	
}