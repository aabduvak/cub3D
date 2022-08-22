/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:00:47 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 22:48:40 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_line(int fd, char **str, int f)
{
	int		i;
	char	*s;

	i = -1;
	*str = get_next_line(fd);
	if (!*str)
		return (-1);
	if (f)
		s = ft_strtrim(*str, " \n\t\v\f\r");
	else
		s = ft_strdup(*str);
	free(*str);
	while (s && s[++i])
	{	
		if (!ft_isspace(s[i]))
		{
			*str = s;
			return (0);
		}
	}
	free(s);
	*str = NULL;
	return (0);
}
