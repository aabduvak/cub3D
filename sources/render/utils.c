/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:02:07 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:11:26 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	image_put_pixel(t_image *img, int x, int y, int color)
{
	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return ;
	*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))) = color;
}

int	image_get_pixel(t_image *img, int x, int y)
{
	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return (0);
	return (*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))));
}

int	float_approximately(float a, float b)
{
	return (a - b < 0.0001f && a - b > -0.0001f);
}

int	int_abs(int i)
{
	return (i * ((i > 0) * 2 - 1));
}

float	float_abs(float i)
{
	return (i * ((i > 0) * 2 - 1));
}
