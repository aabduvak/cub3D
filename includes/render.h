/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:51:41 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 17:17:52 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <data_structure.h>

int		image_get_pixel(t_image *img, int x, int y);
int		color_dark(int color, float dark);
int		float_approximately(float a, float b);
int		int_abs(int i);
void	image_put_pixel(t_image *img, int x, int y, int color);
void	fill_screen(t_data *data);
void	render(t_data *data);
void	draw_wall(t_data *data, float distance, float rate, int index);
void	look_slope(t_data *data, float slope, t_player *dir, int index);
void	raycast(t_data *data, float angle, int index);
float	float_abs(float i);

#endif