/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:16:17 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 21:18:40 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	event_up(int key, t_data *data)
{
	if (key == 13)
		data->keys.w = 1;
	else if (key == 1)
		data->keys.s = 1;
	else if (key == 0)
		data->keys.a = 1;
	else if (key == 2)
		data->keys.d = 1;
	else if (key == 123)
		data->keys.left = 1;
	else if (key == 124)
		data->keys.right = 1;
	else if (key == 53)
		exit(0);
	return (0);
}
