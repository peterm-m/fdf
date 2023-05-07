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
	t_img *img;

	img = (t_img *) param;
	if(key == F_ESC)
		ft_end(&img->win);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_win	win;
	t_img	img;
	t_map	*map;

	map = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	//ft_parser(argv[1], map);
	win = ft_program(1920, 1080, "fdf");
	if (!win.mlx)
		return (EXIT_FAILURE);
	img = ft_image(1920, 1080, win);
	mlx_hook(win.win, 17, 1L<<0, ft_end, &win);
	mlx_key_hook(win.win, ft_read_key, &win);
	t_vec2 r0; r0.x = 100; r0.y = 100; int color0 = 0x00FF0000;
	t_vec2 r1; r1.x = 1000; r1.y = 1000; int color1 = 0x000000FF;
	plotLine3d(img,r0, color0, r1, color1);
	mlx_put_image_to_window(win.mlx, win.win, img.ptr, 0, 0);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}