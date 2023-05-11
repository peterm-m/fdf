#include "fdf.h"

void	ft_plot_line(t_img *img, int color, t_vec2 r0, t_vec2 r1)
	{
	t_vec2	dr;
	int		err;

	dr.x = abs(r0.x - r1.x);
	dr.y = -abs(r0.y - r1.y);
	err = dr.x + dr.y;
	while (1)
	{
		ft_put_pixel(*img, r0.x, r0.y, color);
		if ((r0.x == r1.x) && (r0.y == r1.y))
			break ;
		if (2 * err >= dr.y)
		{
			err = err + dr.y;
			r0.x = r0.x + (r1.x - r0.x) / abs(r1.x - r0.x);
		}
		if (2 * err <= dr.x)
		{
			err = err + dr.x;
			r0.y = r0.y + (r1.y - r0.y) / abs(r1.y - r0.y);
		}
	}
}


void	plotLine3d(t_img *img, t_vec2 r0, int color0, t_vec2 r1, int color1)
{
	int	dx = abs(r1.x - r0.x),	sx = r0.x<r1.x ? 1 : -1;
	int	dy = abs(r1.y - r0.y),	sy = r0.y<r1.y ? 1 : -1;
	int	dm = (dx > dy ? dx : dy ), i = dm;
	r1.x = r1.y = dm/2;
	for(;;)
	{
		ft_put_pixel(*img, r0.x, r0.y, color0);
		if (i-- == 0)
			break ;
		r1.x   -= dx; if (r1.x < 0) { r1.x += dm; r0.x += sx; }
		r1.y   -= dy; if (r1.y < 0) { r1.y += dm; r0.y += sy; }
	}
}

/*
void	ft_plot_circle(t_data *data,int color , int rad, t_vec2 r0)
{
	t_vec2 r;
	int err;
	
	r.x = -rad;
	r.y = 0;
	err = 2 - 2*rad;
	while (1)
	{
		my_mlx_pixel_put(data , r0.x - r.x, r0.y + r.y ,color);
		my_mlx_pixel_put(data , r0.x - r.y, r0.y - r.x ,color);
		my_mlx_pixel_put(data , r0.x + r.x, r0.y - r.y ,color);
		my_mlx_pixel_put(data , r0.x + r.y, r0.y + r.x ,color);
		rad = err;
		if (rad <= r.y)
			err += ++r.y*2+1;
		if (rad > r.x || err > r.y)
			err += ++r.x*2+1;
		if (r.x > 0)
			break ;
	}
}
*/
