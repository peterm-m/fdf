/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:25:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/17 20:22:47 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_mapline(char *line, t_map *map, int x)
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
		map->arr_z[x][y] = atoi(point[0]);
		free(point[0]);
		if (point[1])
		{
			map->arr_color[x][y] = ft_atoi_base(point[1], 16);
			free(point[1]);
		}
		else
			map->arr_color[x][y] = 0;
		free(point);
		free(points[y++]);
	}
	free(points);
}

static t_map	*ft_newmap(int x, int y)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (new)
	{
		new->max_x = x;
		new->max_y = y;
		new->arr_z = (int **)malloc(x * sizeof(int *));
		if (!new->arr_z)
			exit(EXIT_FAILURE);
		new->arr_color = (int **)malloc(x * sizeof(int *));
		if (!new->arr_color)
			exit(EXIT_FAILURE);
		while (x-- > 0)
		{
			new->arr_z[x] = (int *)malloc(y);
			if (!new->arr_z[x])
				exit(EXIT_FAILURE);
			new->arr_color[x] = (int *)malloc(y);
			if (!new->arr_color[x])
				exit(EXIT_FAILURE);
		}
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

void	ft_parser(char *path, t_map **map)
{
	char	*file;
	char	**lines;
	char	line;

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

	if ((x <= map->max_x) && (x >= 0) && (y <= map->max_y) && (y >= 0))
	{
		p.r.x = (float)x;
		p.r.y = (float)y;
		p.r.z = (float)map->arr_z[x][y];
		p.color = map->arr_color[x][y];
	}
	return (p);
}

/*
 *	 save map
 *	|----------------------------------------------------------|
 *	| (x0,y0), (x0,y1), ... , (x0,ymax), (x1,y0)...(xmax,ymax) |
 *	|----------------------------------------------------------|
 */