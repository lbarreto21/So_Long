/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:01 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/31 17:14:57 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_mlx(t_mlx *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->map->player_img);
	mlx_destroy_image(data->mlx, data->map->wall_img);
	mlx_destroy_image(data->mlx, data->map->floor_img);
	mlx_destroy_image(data->mlx, data->map->collectable_img);
	mlx_destroy_image(data->mlx, data->map->exit_img);
}

void	free_data(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->map_size_y)
	{
		free(data->grid[i]);
		i++;
	}
	free(data->grid);
	free(data->map);
}

void	free_mlx(t_mlx *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	is_valid_character(char c)
{
	if (c == 'P' || c == '0' || c == '1' || c == 'E' || c == 'C' || c == '\n')
		return (1);
	return (0);
}

int	verify_extension(char *file_ext)
{
	char	*right_ext;
	int		max;

	max = ft_strlen(file_ext);
	if (ft_strlen(right_ext) > max)
		max = ft_strlen(right_ext);
	right_ext = ft_strdup(".ber");
	if (ft_strncmp(file_ext, right_ext, max))
	{
		free(right_ext);
		return (0);
	}
	free(right_ext);
	return (1);
}
