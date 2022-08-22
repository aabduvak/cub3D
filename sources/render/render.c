/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:51:17 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:29:09 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	render(t_data *data)
{
	const float	view_angle = 1.5f / 2;
	const float	add = view_angle / WIN_WIDTH;
	float		angle;
	int			pixels;

	fill_screen(data);
	pixels = WIN_WIDTH;
	angle = -(view_angle / 2);
	while (pixels--)
	{
		raycast(data, angle, pixels);
		angle += add;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}
