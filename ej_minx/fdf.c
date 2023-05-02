#include <fdf.h>

int	main(void)
{
	t_win	win;
	t_img	img;

	win = ft_program(1920, 1080, "Hello world!");
	if (!win.mlx)
		return (EXIT_FAILURE);
	img = ft_image(1920, 1080, win);
	mlx_hook(win.win, 17, 1L<<0, ft_end, &win);
	mlx_key_hook(win.win, ft_read_key, &win);
	mlx_put_image_to_window(win.mlx, win.win, img.ptr, 0, 0);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}
