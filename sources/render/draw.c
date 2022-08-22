/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:00:13 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:08:00 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_wall(t_data *data, float distance, float rate, int index)
{
	int		draw;
	float	rate_i;
	int		start;
	int		end;
	float	dark;

	dark = 2.0f / distance;
	if (dark >= 1)
		dark = 1;
	draw = (5 / distance) * (WIN_HEIGHT * 0.3f);
	rate_i = (float)data->imgs[data->active_img].height / draw;
	start = (WIN_HEIGHT - draw) / 2;
	end = 0;
	if (start < 0)
	{
		draw += start;
		end = -start;
	}
	while (draw-- > end)
		image_put_pixel(&data->screen, index, draw + start,
			color_dark(image_get_pixel(&data->imgs[data->active_img],
					data->imgs[data->active_img].width * rate,
					draw * rate_i), dark));
}
