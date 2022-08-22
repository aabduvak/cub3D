/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:02:52 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/23 00:29:36 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_map	*create_map(char *filename);
t_map	*init_map(int fd);
int		get_map_fd(t_map *map, int fd);
int		get_param(t_map *map, int fd, char *s);
int		check_wall(t_map *map, char ch);
int		check_map(t_map *map, char *s, char *s2);
void	get_position(t_map *map);

#endif