/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:25:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/13 14:51:32 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mapline(char *line, t_map *map, int x)
{
	char	**points;
	char	**point;
	int		y;

	y = 0;
	points = ft_split(line, ' ');
	free(line);
	while (points[y])
	{
		point = ft_split(points[y], ',');
		map->arr_z[map->max_y * x + y] = ft_atoi(point[0]);
		free(point[0]);
		if (point[1])
		{
			map->arr_color[map->max_y * x + y] = ft_atoi_base(point[1], 16);
			free(point[1]);
		}
		else
			map->arr_color[map->max_y * x + y] = 0xFFFFFFFF;
		free(point);
		free(points[y++]);
	}
	free(points);
}

t_map	*ft_newmap(int x, int y)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (new)
	{
		new->max_x = x;
		new->max_y = y;
		new->arr_z = (int *)malloc(x * y);
		if (!new->arr_z)
		{
			free(new);
			return (NULL);
		}
		new->arr_color = (int *)malloc(x * y);
		if (!new->arr_color)
		{
			free(new->arr_z);
			free(new);
			return (NULL);
		}
	}
	return (new);
}

t_map	*ft_fillmap(char **lines)
{
	t_map	*map;
	char	**points;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (lines[++x])
		continue ;
	points = ft_split(lines[0], ' ');
	while (points[y])
		free(points[y++]);
	free(points);
	map = ft_newmap(x, y);
	x = -1;
	while (lines[++x])
		ft_mapline(lines[x], map, x);
	return (map);
}

t_map	*ft_parser(char *path)
{
	t_map	*map;
	char	*file;
	char	**lines;
	char	line;

	file = ft_getfile(path);
	if (!file)
		return (NULL);
	lines = ft_split(file, '\n');
	free(file);
	map = ft_fillmap(lines);
	free(lines);
	return (map);
}

/*
 *	giuardado del mapa
 *	|----------------------------------------------------------|
 *	| (x0,y0), (x0,y1), ... , (x0,ymax), (x1,y0)...(xmax,ymax) |
 *	|----------------------------------------------------------|
 */