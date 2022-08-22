/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:59:13 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/23 00:00:29 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_wall(t_map *map, char ch)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (map->data[i] && map->data[i + 1])
	{
		s = map->data[i];
		j = 0;
		while (s[j])
		{
			if (s[j] == ch && ((!j || s[j - 1] == ' '
						|| !s[j + 1] || s[j + 1] == ' ')
					|| ((size_t)j + 1 > ft_strlen(map->data[i - 1])
						|| map->data[i - 1][j] == ' ')
				|| ((size_t)j + 1 > ft_strlen(map->data[i + 1])
					|| map->data[i + 1][j] == ' ')))
				return (-1);
			j++;
		}	
		i++;
	}
	if (ft_strchr(map->data[i], ch) || ft_strchr(map->data[0], ch))
		return (-1);
	return (0);
}
