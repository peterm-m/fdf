/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:25:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/18 20:57:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_mapline(char *line, t_map *map, int y)
{
	char	**points;
	char	**point;
	int		x;

	x = 0;
	points = ft_split(line, ' ');
	free(line);
	while (x < map->ncol)
	{
		if (!points[x])
			exit(EXIT_FAILURE);
		point = ft_split(points[x], ',');
		map->z[y * map->ncol + x] = atoi(point[0]);
		free(point[0]);
		if (point[1])
		{
			map->color[y * map->ncol + x] = ft_atoi_base(point[1], 16);
			free(point[1]);
		}
		else
			map->color[y * map->ncol + x] = 0xFFFFFFFF;
		free(point);
		free(points[x++]);
	}
	free(points);
}

static t_map	*ft_newmap(int x, int y)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (new)
	{
		new->ncol = x;
		new->nrow = y;
		new->z = (int *)malloc(x * y * sizeof(int));
		if (!new->z)
			exit(EXIT_FAILURE);
		new->color = (int *)malloc(x * y * sizeof(int));
		if (!new->color)
			exit(EXIT_FAILURE);
	}
	return (new);
}

static t_map	*ft_fillmap(char **lines)
{
	t_map	*map;
	char	**points;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (lines[y])
		y++ ;
	points = ft_split(lines[0], ' ');
	while (points[x])
		free(points[x++]);
	free(points);
	map = ft_newmap(x, y);
	y = -1;
	while (++y < map->nrow)
		ft_mapline(lines[y], map, y);
	return (map);
}

void	ft_parser(char *path, t_map **map)
{
	char	*file;
	char	**lines;

	file = ft_getfile(path);
	if (!file)
		exit(EXIT_FAILURE);
	lines = ft_split(file, '\n');
	free(file);
	*map = ft_fillmap(lines);
	free(lines);
}

t_point	ft_point(t_map *map, int x, int y)
{
	t_point	p;

	p.r.x = (float)x;
	p.r.y = (float)y;
	p.r.z = (float)map->z[y * map->ncol + x];
	p.color = map->color[y * map->ncol + x];
	return (p);
}

/*
 *	 save map
 *	|----------------------------------------------------------|
 *	| (x0,y0), (x0,y1), ... , (x0,ymax), (x1,y0)...(xmax,ymax) |
 *	|----------------------------------------------------------|
 */