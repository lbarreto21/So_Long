/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:01 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/16 14:51:20 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_map data)
{
	int	i;

	i = 0;
	while (i < data.map_size_y)
	{
		free(data.grid[i]);
		i++;
	}
	free(data.grid);
	free(data.map);
}

int	is_valid_character(char c)
{
	if (c == 'P' || c == '0' || c == '1' || c == 'E' || c == 'C' || c == '\n')
		return (1);
	return (0);
}
