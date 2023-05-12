/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:25:52 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/12 20:21:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_wc_bytes(char *path)
{
	size_t	len;
	size_t	aux;
	int		fd;
	char	buf[BUFSIZ];

	fd = open(path, O_RDONLY);
	len = read(fd, buf, BUFSIZ);
	while (1)
	{
		aux = read(fd, buf, BUFSIZ);
		if (aux > 0)
			len += aux;
		else
		{
			close(fd);
			return (len);
		}
	}
}

char	*ft_getfile(char *path)
{
	size_t	len_file;
	char	*file;
	int		fd;

	len_file = ft_wc_bytes(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = (char *)malloc(len_file + 1);
	if (file)
	{
		file[len_file] = '\0';
		read(fd, file, len_file);
		close(fd);
	}
	return (file);
}

/*
 *	giuardado del mapa
 *	|----------------------------------------------------------|
 *	| (x0,y0), (x0,y1), ... , (x0,ymax), (x1,y0)...(xmax,ymax) |
 *	|----------------------------------------------------------|
 */

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

t_map	*ft_fillmap(char **lines)s
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
