/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:55:12 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/09 18:48:30 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_wc_lines(char *path)
{}

size_t	ft_wc_word(char *path)
{}

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

// test mapas:
//	- no todos terminan las lineas con space\n
//	- algunos alternan entre solo z y z,color
//	- comprobar si hay mapas con lineas desiguales.
//	- crear mapa test para prueba de estres: concatenar t1.fdf varias veces.

// posible map:
// map_color
// map_z

static void	ft_mapline(char *line, t_map *map)
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
		free(point[0]);
		if (point[1])
			free(point[1]);
		else
			printf("\n");
		free(point);
		free(points[y++]);
	}
	free(points);
}

t_map	*ft_newmap(void)
{
	t_map	*new;

	new = (t_map *) malloc(sizeof(t_map));
	if (new)
	{
		new->max_x = 0;
		new->max_y = 0;
		new->arr_z = NULL;
		new->arr_color = NULL;
	}
	return (new);
}

void	ft_delmap(t_map *map)
{
	if (map->arr_z)
		free(map->arr_z);
	if (map->arr_color)
		free(map->arr_color);
	free(map);
}

void	ft_fillmap(char **lines, t_map *map)
{
	char **points;

	while(lines[++map->max_x])
		continue ;
	points = ft_split(lines[0], ' ');
	while(points[++map->max_y])
		continue ;
	map->arr_z = (int *) malloc(map->max_x * map->max_y);
	if (! map->arr_z)
		return ;
	map->arr_color = (int *) malloc(map->max_x * map->max_y);
	if (! map->arr_color)
		return ;
}

int	ft_parser(char *path)
{
	char	*file;
	char	**lines;
	char	line;
	t_map	*map;

	file = ft_getfile(path);
	if (!file)
		return (EXIT_FAILURE);
	map = ft_newmap();
	if (!map)
		return (EXIT_FAILURE);
	lines = ft_split(file, '\n');
	free(file);
	ft_fillmap(lines, map);
	free(lines);
	return(EXIT_SUCCESS);
}
