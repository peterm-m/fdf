#include <fdf.h>

t_img	ft_image(int w, int h, t_win win)
{
	t_img	img;

	img.win = win;
	img.ptr = mlx_new_image(win.mlx, w, h);
	img.addr = mlx_get_data_addr(img.ptr, &(img.bpp),
			&(img.size_line), &(img.endian));
	img.w = w;
	img.h = h;
	return (img);
}

int	ft_rgb_color(int o, int r, int g, int b)
{
	(void ) o;
	(void ) r;
	(void ) g;
	(void ) b;
	return(0);
}

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x <= img.w && y <= img.h)
	{
		dst = img.addr + (y * img.size_line + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}
