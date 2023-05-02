#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define F_SIZE_X 1080
#define F_SIZE_Y 1920
#define F_TITLE "Hola"


typedef struct s_pix {
	int	x;
	int	y;
} t_pix;

typedef struct s_vec {
	int	x;
	int	y;
	int	z;
} t_vec;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		win_shape[2];
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int  x, int y , int color) // int (*color)(int, int)
{
	char	*dst;

	dst = data->addr + ( y * data->line_length +  x  * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;// color(x,y);
}

void	ft_plot_line(t_data *data, int color, t_pix r0, t_pix r1)
{
	t_pix dr;
	int err;

	dr.x = abs(r0.x - r1.x);
	dr.y = -abs(r0.y - r1.y);
	err = dr.x + dr.y;
	while (1)
	{
		my_mlx_pixel_put(data ,r0.x, r0.y, color);
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

void	ft_plot_polygon()
{ return ; }
//
// pasa por dos puntos con un radio
// circle by three point
// Elipse
// arco elipse
// Becier
// fill region 

void ft_plot_mesh()
{
	 return;
}

int close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	printf("%d", keycode);
	exit(EXIT_SUCCESS);
}

void	ft_fdf()
{
//	t_vars *vars;

//	vars->mlx = mlx_init();
//	vars->win = mlx_new_window(vars->mlx, F_SIZE_X, F_SIZE_Y, F_TITLE);
//	mlx_hook(vars->win, 2, 1L<<0, close, &vars);
//	// read map
//	// make  image
//	mlx_loop(vars->mlx);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_hook(vars.win, 2 , 1L<<0, close, &vars );
	mlx_hook(vars.win, 17, 1L<<2, close, &vars );
	t_pix  p0, p1;
	while (p0.y < 1080)
	{
		p0.x = 1;
		p0.y += 1080/10;
		p1.x = 1919;
		p1.y += 1080/10;
		ft_plot_line(&img, 0x00FF0000, p0, p1);
	}
	p0.x = 1;
	p1.x = 1;
	while (p0.x < 1920)
	{
		p0.x += 1920/10;
		p0.y = 1;
		p1.x += 1920/10;
		p1.y = 1079;
		ft_plot_line(&img, 0x00FF0000, p0, p1);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	exit(EXIT_SUCCESS);
}

