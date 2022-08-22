/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:55:26 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/23 00:00:23 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_map(t_map *map, char *s, char *s2)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (!ft_strchr(s, map->data[i][j]))
				return (-1);
			if (ft_strchr(s2, map->data[i][j]))
				k++;
			j++;
		}
		i++;
	}
	if (1 != k)
		return (-1);
	i = 0;
	return (0);
}
