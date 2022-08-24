/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:57:50 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/24 04:48:11 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	*init_map(int fd)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (-1 == get_param(map, fd, NULL) || -1 == map->c.f || -1 == map->f.f)
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		clear_map(map);
		return (NULL);
	}
	if (-1 == get_map_fd(map, fd) || -1 == check_map(map, "01NSEW ", "NWES")
		|| check_wall(map, '0') || check_wall(map, 'N')
		|| check_wall(map, 'S') || check_wall(map, 'W') || check_wall(map, 'E'))
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		clear_map(map);
		return (NULL);
	}
	return (map);
}
