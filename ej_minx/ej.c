


void	ft_plot_line(t_data *data, int color, t_p r0, t_p r1)
{
	t_p dr;
	double err;

	dr.x = fabs(r0.x - r1.x);
	dr.y = -fabs(r0.y - r1.y);
	err = dr.x + dr.y;
	while (1)
	{
		my_mlx_pixel_put(data ,r0, color);
		if (( (int) r0.x == (int) r1.x) && ((int) r0.y == (int) r1.y))
			break ;
		if (2*err >= dr.y)
		{
			err = err + dr.y;
			r0.x = r0.x + (r1.x - r0.x)/fabs(r1.x - r0.x);
		}
		if (2*err <= dr.x)
		{
			err = err + dr.x;
			r0.y = r0.y + (r1.y - r0.y)/fabS(r1.y - r0.y);
		}
	}
}
