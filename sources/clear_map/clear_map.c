/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:22:52 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 21:04:18 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	clear_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
		free(arg[i++]);
	if (arg)
		free(arg);
	return (0);
}

int	clear_map(t_map *map)
{
	if (!map)
		return (1);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	clear_arg(map->data);
	free(map);
	return (0);
}
