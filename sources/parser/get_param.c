/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:59:37 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/22 22:56:53 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*give_str( char *cmp, char	*s)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	if (0 != ft_strncmp(cmp, s, ft_strlen(cmp)))
		return (NULL);
	i = ft_strlen(cmp);
	while (s[i] && ft_isspace(s[i]))
		i++;
	tmp = ft_substr(s, i, ft_strlen(&s[i]));
	free(s);
	return (tmp);
}

static int	clear_pixel(char *s)
{
	char	*ss;
	int		c;
	int		i;

	i = 0;
	ss = ft_strtrim(s, " \n\t\v\f\r");
	while (ss && ss[i])
	{
		if (!ft_isdigit(ss[i]))
		{
			free(ss);
			return (-1);
		}
		i++;
	}
	c = ft_atoi(ss);
	free(ss);
	if (c > 255 || c < 0)
		return (-1);
	return (c);
}

static int	give_pixel(t_pixel *p, char *cmp, char *s)
{
	int		i;
	char	**sp;
	int		f;

	f = -1;
	i = ft_strlen(cmp);
	sp = ft_split(&s[i], ',');
	free(s);
	i = 0;
	while (sp[i])
		i++;
	if (i == 3)
	{
		p->r = clear_pixel(sp[0]);
		p->g = clear_pixel(sp[1]);
		p->b = clear_pixel(sp[2]);
		if (p->r >= 0 && p->g >= 0 && p->b >= 0)
			f = 1;
	}
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (f);
}

int	get_param(t_map *map, int fd, char *s)
{
	while ((!map->no || !map->so) || !map->we
		|| !map->ea || !map->f.f || !map->c.f)
	{
		if (-1 == get_line(fd, &s, 1))
			return (-1);
		if (s && !map->no && 0 == ft_strncmp("NO ", s, ft_strlen("NO ")))
			map->no = give_str("NO ", s);
		else if (s && !map->so && 0 == ft_strncmp("SO ", s, ft_strlen("SO ")))
			map->so = give_str("SO ", s);
		else if (s && !map->we && 0 == ft_strncmp("WE ", s, ft_strlen("WE ")))
			map->we = give_str("WE ", s);
		else if (s && !map->ea && 0 == ft_strncmp("EA ", s, ft_strlen("EA ")))
			map->ea = give_str("EA ", s);
		else if (s && !map->f.f && 0 == ft_strncmp("F ", s, ft_strlen("F ")))
			map->f.f = give_pixel(&map->f, "F ", s);
		else if (s && !map->c.f && 0 == ft_strncmp("C ", s, ft_strlen("C ")))
			map->c.f = give_pixel(&map->c, "F ", s);
		else if (s)
		{
			free(s);
			return (-1);
		}
	}
	return (1);
}
