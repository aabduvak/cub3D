/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:11:17 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 13:56:40 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	allocate_map(t_data *data, char **line)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = -1;
	while (line[++y])
	{
		x = 0;
		while (line[y][x])
			x++;
		if (data->x_size < x)
			data->x_size = x;
	}
	data->y_size = y;
	data->map = (int **)ft_calloc(y, sizeof(int *));
	while (++i < y)
		data->map[i] = (int *) ft_calloc(data->x_size, sizeof(int));
}

void	get_map(t_data *data, char **line)
{
	int	x;
	int	y;
	int	lock;

	y = -1;
	allocate_map(data, line);
	while (++y < data->y_size)
	{
		x = -1;
		lock = 0;
		while (++x < data->x_size)
		{
			if (!lock && (line[y][x] == '\0' || line[y][x] == '\n'))
				lock = 1;
			if (lock)
				data->map[y][x] = ' ';
			else
				data->map[y][x] = line[y][x];
		}
	}
}
