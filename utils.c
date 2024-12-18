/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:06:56 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/18 11:23:38 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int print_error(int error_code)
{
    ft_putstr_fd("ERROR: ", 2);
    if (error_code == ARG_ERROR)
        return (ft_putstr_fd("Wrong number of arguments", 2), ARG_ERROR);
    if (error_code == EXTENSION_ERROR)
        return (ft_putstr_fd("Wrong extension of file", 2), EXTENSION_ERROR);
}

int find_occurences(char *str, char c)
{
    int i;
    int ocurrence;

    i = 0;
    ocurrence = 0;
    while (str[i])
    {
        if (str[i] == c)
            ocurrence++;
        i++;
    }
    return (ocurrence);
}

void    flood_fill(t_map *map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->map_size_x || y >= map->map_size_y)
        return ;
    if (map->map[x][y] == '1')
        return ;
    if (map->map[x][y] == 'C')
        map->valid_collectables++;
    else if (map->map[x][y] == 'E')
        map->valid_exit++;
    flood_fill(map, x-1, y);
    flood_fill(map, x+1, y);
    flood_fill(map, x, y+1);
    flood_fill(map, x, y-1);
}