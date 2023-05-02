#include "minXej.h"

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
