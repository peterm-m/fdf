#include <fdf.h> 

void	ft_plot_line(t_img *img, int color, t_pix r0, t_pix r1)
{
	t_pix dr;
	int err;

	dr.x = abs(r0.x - r1.x);
	dr.y = -abs(r0.y - r1.y);
	err = dr.x + dr.y;
	while (1)
	{
		ft_put_pixel(*img ,r0.x, r0.y, color);
		if (( r0.x ==  r1.x) && ( r0.y == r1.y))
			break ;
		if (2*err >= dr.y)
		{
			err = err + dr.y;
			r0.x = r0.x + (r1.x - r0.x)/abs(r1.x - r0.x);
		}
		if (2*err <= dr.x)
		{
			err = err + dr.x;
			r0.y = r0.y + (r1.y - r0.y)/abs(r1.y - r0.y);
		}
	}
}


