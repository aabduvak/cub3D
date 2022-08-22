/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 00:27:08 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/23 00:29:01 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_position(t_map *map)
{
	int		i;
	int		k;
	int		t;

	t = 0;
	i = -1;
	while (map->data[++i])
	{
		k = -1;
		while (map->data[i][++k])
		{
			if (ft_strchr("WESN", map->data[i][k]))
			{
				while (map->data[i][k] != "ENWS"[t])
					t++;
				map->ang = t * 90;
				map->data[i][k] = '0';
				map->y = i;
				map->x = k;
				return ;
			}
		}
	}
}
