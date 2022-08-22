/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:53:23 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 13:56:06 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	image_controller(t_data *data)
{
	if (!data->imgs[0].img || !data->imgs[1].img
		|| !data->imgs[2].img || !data->imgs[3].img)
	{
		ft_putstr_fd("image error!\n", 2);
		exit(1);
	}
}

/* all data must be freed */

void	get_args(t_data *data, t_map *map)
{
	data->imgs[0].img = mlx_xpm_file_to_image(data->mlx,
			map->no, &data->imgs[0].width, &data->imgs[0].height);
	data->imgs[1].img = mlx_xpm_file_to_image(data->mlx,
			map->so, &data->imgs[1].width, &data->imgs[1].height);
	data->imgs[2].img = mlx_xpm_file_to_image(data->mlx,
			map->ea, &data->imgs[2].width, &data->imgs[2].height);
	data->imgs[3].img = mlx_xpm_file_to_image(data->mlx,
			map->we, &data->imgs[3].width, &data->imgs[3].height);
	image_controller(data);
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img,
			&data->imgs[0].bbp, &data->imgs[0].line_len, &data->imgs[0].endian);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img,
			&data->imgs[1].bbp, &data->imgs[1].line_len, &data->imgs[1].endian);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img,
			&data->imgs[2].bbp, &data->imgs[2].line_len, &data->imgs[2].endian);
	data->imgs[3].addr = mlx_get_data_addr(data->imgs[3].img,
			&data->imgs[3].bbp, &data->imgs[3].line_len, &data->imgs[3].endian);
	data->floor_color = (map->f.r << 16) + (map->f.g << 8) + map->f.b;
	data->ceil_color = (map->c.r << 16) + (map->c.g << 8) + map->c.b;
}

/**
 * RGB -> (0, 0, 0) -> black
 * RGB -> (255, 255, 255) -> white
 * Range -> (0 - 255, 0 -> 255, 0 -> 255)
 */