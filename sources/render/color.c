/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:10:22 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:11:11 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	color_dark(int color, float dark)
{
	int	r;
	int	g;
	int	b;

	r = color & 0x000000FF;
	r *= dark;
	g = (color & 0x0000FF00) >> 8;
	g *= dark;
	b = (color & 0x00FF0000) >> 16;
	b *= dark;
	return (r | (g << 8) | (b << 16));
}
