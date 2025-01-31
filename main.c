/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:47 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/31 20:20:30 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	data;
	int		verification;
	t_mlx	mlx_data;

	if (argc != 2)
		return (print_error(ARG_ERROR));
	if (!verify_extension(argv[1]))
		return (print_error(EXTENSION_ERROR));
	data.map = open_map(argv[1]);
	if (!data.map)
		return (print_error(MAP_ERROR));
	data = read_map(data.map);
	verification = verify_map(&data);
	if (verification < 0)
	{
		free_data(&data);
		return (print_error(verification));
	}
	mlx_data = mlx_initialization(&data);
	mlx_data.map = &data;
	render_map(data, mlx_data);
	mlx_key_hook(mlx_data.window, movement_player, &mlx_data);
	mlx_loop(mlx_data.mlx);
	free_mlx(&mlx_data);
	return (0);
}
