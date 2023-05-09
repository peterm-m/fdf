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

void	ft_parser(char *path, t_map *map)
{
	char	buf[BUFSIZ];
	int		fd;
	int		len;
	int		aux;

	fd = open(path, O_RDONLY);
	len = read(fd, buf, BUFSIZ);
	aux = len;
	printf("%d\n", __LINE__);
	while (aux > 0)
	{
		aux = read(fd, buf, BUFSIZ);
		if (aux > 0)
			len += aux;
		else
			break ;
	}
	printf("%d\n", len);
}
//	fd = open(path, O_RDONLY);

size_t	ft_file_len(char *path)
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

	len_file = ft_file_len(path);
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

static void	ft_mapline(char *line, int x)
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
		printf("x = %d, y = %d z = %s ", x, y, point[0]);
		free(point[0]);
		if (point[1])
		{
			printf("color %s\n", point[1]);
			free(point[1]);
		}
		else
			printf("\n");
		free(point);
		free(points[y++]);
	}
	free(points);
}

int	main(void)
{
	char	*file;
	char	**lines;
	char	line;
	int		i;

	i = -1;
	file = ft_getfile("../test_maps/t2.fdf");
	if (!file)
		return (EXIT_FAILURE);
	lines = ft_split(file, '\n');
	free(file);
	while (lines[++i])
		ft_mapline(lines[i], i);
	free(lines);
	printf("num lines %d\n", i);
}
