/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:50:47 by lbarreto          #+#    #+#             */
/*   Updated: 2024/12/18 11:04:52 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*file_extension;
	char	*map;

	if (argc != 2)
		return (print_error(ARG_ERROR));
	file_extension = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (!file_extension)
		return (print_error(EXTENSION_ERROR));
	map = open_map(argv[1]);
	printf("mapa:\n%s\n", map);
	free(map);
	return (0);
}
