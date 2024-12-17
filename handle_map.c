/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:19:18 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/12 01:59:59 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *open_map(char *file)
{
    int     fd;
    char    *map;
    char    *line;

    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    map = ft_strdup("");
    while (line)
    {
        map = ft_strjoin(map, line);
        line = get_next_line(fd);
    }
    return (map);
}
