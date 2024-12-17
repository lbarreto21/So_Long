/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:06:56 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/12 00:22:10 by lbarreto         ###   ########.fr       */
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