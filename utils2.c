/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:01 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/31 20:10:50 by lbarreto         ###   ########.fr       */
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

int	verify_extension(char *file_path)
{
	char	*file_extension;

	file_extension = ft_strnstr(file_path, ".ber", ft_strlen(file_path));
	if (!file_extension)
		return (0);
	return (!ft_strncmp(file_extension, ".ber", 5));
}
