/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:14:08 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 21:35:27 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	event_exit(void *tmp)
{
	(void)tmp;
	exit(0);
}

void	event_handler(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, event_up, data);
	mlx_hook(data->mlx_win, 3, 0, event_down, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_hook(data->mlx_win, 17, 0, event_exit, 0);
}
