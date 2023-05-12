/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:06:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/12 19:35:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	ft_program(int h, int w, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

int	ft_end(t_win *win)
{
	if (win)
		mlx_destroy_image(win->mlx, win->win);
	exit(EXIT_SUCCESS);
}

int	ft_read_key(int key, void *param)
{
	t_img	*img;

	img = (t_img *) param;
	if (key == F_ESC)
		ft_end(&img->win);
	return (EXIT_SUCCESS);
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

int	main(int argc, char **argv)
{
	t_win	win;
	t_img	img;
	t_map	*map;

	if (argc != 2)
		return (EXIT_FAILURE);
	map = ft_parser(argv[1]);
	win = ft_program(1920, 1080, "fdf");
	if (!win.mlx)
		return (EXIT_FAILURE);
	img = ft_image(1920, 1080, win);
	mlx_hook(win.win, 17, 1L << 0, ft_end, &win);
	mlx_key_hook(win.win, ft_read_key, &win);
	mlx_put_image_to_window(win.mlx, win.win, img.ptr, 0, 0);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}
