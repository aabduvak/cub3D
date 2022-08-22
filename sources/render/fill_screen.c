/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:55:34 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:39:23 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_screen(t_data *data)
{
	int		x;
	int		y;
	int		middle;

	middle = data->screen.height / 2;
	y = -1;
	while (++y < middle)
	{
		x = -1;
		while (++x < data->screen.width)
			image_put_pixel(&data->screen, x, y, data->ceil_color);
	}
	while (++y < data->screen.height)
	{
		x = -1;
		while (++x < data->screen.width)
			image_put_pixel(&data->screen, x, y, data->floor_color);
	}
}
