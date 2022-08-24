/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:38:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/24 04:49:31 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	start_game(t_data *data, t_map *map)
{
	data->pos.x = map->x + 0.5f;
	data->pos.y = map->y + 0.5f;
	data->look = (map->ang + 180) * ANLE_TO_RADIAN;
	render(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map;

	if (argc != 2)
		return (-1);
	map = create_map(argv[1]);
	if (map == NULL)
		return (-1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,
			WIN_WIDTH, WIN_HEIGHT, "GTA Vice City");
	data.screen.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.screen.width = WIN_WIDTH;
	data.screen.height = WIN_HEIGHT;
	data.screen.addr = mlx_get_data_addr(data.screen.img,
			&data.screen.bbp, &data.screen.line_len, &data.screen.endian);
	get_data(&data, map);
	start_game(&data, map);
	event_handler(&data);
	mlx_loop(data.mlx);
	return (0);
}
