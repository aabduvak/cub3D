/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:50:27 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:23:39 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_data(t_data *data, t_map *map)
{
	if (!data || !map)
		return (1);
	get_args(data, map);
	get_map(data, map->data);
	return (0);
}
