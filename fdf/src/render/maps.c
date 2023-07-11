/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:25:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/11 19:57:32 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mapline(char *line, t_map *map, int y)
{
	char	**points;
	char	**point;
	float	color;
	int		x;

	x = 0;
	points = ft_split(line, ' ');
	if (!points[x])
		exit(EXIT_FAILURE);
	free(line);
	while (x < map->ncol)
	{
		point = ft_split(points[x], ',');
		map->p[y * map->ncol + x].r = ft_vec4((float)x, (float)y,
				(float)atoi(point[0]), 1.0f);
		free(point[0]);
		map->p[y * map->ncol + x].color = ft_vec4(0.0f, 255.0f, 255.0f, 255.0f);
		if (point[1])
		{
			color = (float)ft_atoi_base(point[1], 16);
			map->p[y * map->ncol + x].color = ft_vec4(get_a(color),
					get_r(color), get_g(color), get_b(color));
			free(point[1]);
		}
		free(point);
		free(points[x++]);
	}
	free(points);
}

t_map	*ft_newmap(int x, int y)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (new)
	{
		new->ncol = x;
		new->nrow = y;
		new->p = (t_point *)malloc(x * y * sizeof(t_point));
		if (!new->p)
			exit(EXIT_FAILURE);
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

//oid	ft_print_map(t_map *m)
//
//	int		x;
//	int		y;
//	t_point	p;
//
//	y = -1;
//	ft_printf("MAP:\n");
//	while (++y < m->nrow)
//	{
//		x = -1;
//		while (++x < m->ncol)
//		{
//			p = point(m, x, y);
//			ft_printf("%d|%d ", p.r.z, p.color);
//		}
//		ft_printf("\n");
//	}
//	ft_printf("nrow %d ncol %d\n", m->nrow, m->ncol);
//
//
//_point	ft_point(t_map *map, int x, int y)
//
//	t_point	p;
//
//	p.r.x = (float)x;
//	p.r.y = (float)y;
//	p.r.z = (float)map->z[y * map->ncol + x];
//	p.r.w = 1.0f;
//	p.color.r = get_r(map->color[y * map->ncol + x]);
//	p.color.g = get_g(map->color[y * map->ncol + x]);
//	p.color.b = get_b(map->color[y * map->ncol + x]);
//	p.color.a = get_a(map->color[y * map->ncol + x]);
//	return (p);
//
//
/*
 *	 save map
 *	|----------------------------------------------------------|
 *	| (x0,y0), (x0,y1), ... , (x0,ymax), (x1,y0)...(xmax,ymax) |
 *	|----------------------------------------------------------|
 */