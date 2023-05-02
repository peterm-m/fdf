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

int	main(void)
{
	t_win	win;
	t_img	img;

	win = ft_program(1920, 1080, "Hello world!");
	if (!win.mlx)
		return (EXIT_FAILURE);
	img = ft_image(1920, 1080, win);
	mlx_hook(win.win, 17, 1L<<0, ft_end, &win);
	t_vec2 r0;
	t_vec2 r1;
	r0.x = 1; r0.y = 1;
	r1.x = 100; r1.y = 100;
	ft_plot_line( &img, 0x00FFFFFF,r0,r1);
	mlx_key_hook(win.win, ft_read_key, &win);
	mlx_put_image_to_window(win.mlx, win.win, img.ptr, 0, 0);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}
