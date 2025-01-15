/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:01 by lbarreto          #+#    #+#             */
/*   Updated: 2025/01/15 16:46:35 by lbarreto         ###   ########.fr       */
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

int	verify_map_characters(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_valid_character(map[i]) == 0)
			return (MAP_INVALID_CHARACTER_ERROR);
		i++;
	}
	return (1);
}
