/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:06:56 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/18 15:05:27 by lbarreto         ###   ########.fr       */
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

int find_player_x(t_map data)
{
    int i;
    int j;

    i = 0;
    while (i < data.map_size_x)
    {
        j = 0;
        while (j < data.map_size_y)
        {
            if (data.map[i][j] == 'P')
                return (i);
            j++;
        }
        i++;
    }
    return (0);
}

int find_player_y(t_map data)
{
    int i;
    int j;

    i = 0;
    while (i < data.map_size_x)
    {
        j = 0;
        while (j < data.map_size_y)
        {
            if (data.map[i][j] == 'P')
                return (j);
            j++;
        }
        i++;
    }
    return (0);
}

void    flood_fill(t_map *data, int x, int y)
{
    if (x < 0 || y < 0 || x >= data->map_size_x || y >= data->map_size_y)
        return;
    if (data->map[x][y] == '1')
        return;
    if (data->map[x][y] == 'C')
        data->valid_collectables++;
    else if (data->map[x][y] == 'E')
        data->valid_exit++;
    flood_fill(data, x-1, y);
    flood_fill(data, x+1, y);
    flood_fill(data, x, y-1);
    flood_fill(data, x, y+1);
}