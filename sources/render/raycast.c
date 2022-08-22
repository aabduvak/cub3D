/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:03:08 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:42:38 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	raycast(t_data *data, float angle, int pixels)
{
	float		cos_value;
	float		sin_value;
	t_player	dir;

	cos_value = cosf(angle + data->look);
	sin_value = sinf(angle + data->look);
	dir.x = (cos_value > 0) * 2 - 1;
	dir.y = (sin_value > 0) * 2 - 1;
	dir.angle = angle;
	look_slope(data, sin_value / cos_value, &dir, pixels);
}
