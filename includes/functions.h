/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:04:27 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 13:59:21 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// INIT DATA
void	get_map(t_data *data, char **line);
void	get_args(t_data *data, t_map *map);
int		get_data(t_data *data, t_map *map);

#endif