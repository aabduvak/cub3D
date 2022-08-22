/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:20:52 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 21:25:08 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	event_down(int key, t_data *data)
{
	if (key == 13)
		data->keys.w = 0;
	else if (key == 1)
		data->keys.s = 0;
	else if (key == 0)
		data->keys.a = 0;
	else if (key == 2)
		data->keys.d = 0;
	else if (key == 123)
		data->keys.left = 0;
	else if (key == 124)
		data->keys.right = 0;
	return (0);
}
