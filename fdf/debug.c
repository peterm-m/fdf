
#include "fdf.h"


void	print_win(char *name, t_win *w)
{
	printf("win %s mlx %p win %p w %d h %d\n", name, w->mlx, w->win,w->w, w->h);
}

void	print_vec3(char *name, t_vec3 v)
{
	printf("vec3 %s x %f y %f z %f \n", name, v.x, v.y, v.z);
}

void	print_ivec2(char *name, t_ivec2 v)
{
	printf("ivec2 %s x %d y %d \n", name, v.x, v.y);
}

void	print_pix(char *name, t_pixel p)
{
	printf("ivec2 %s x %d y %d color %d\n", name, p.r.x, p.r.y, p.color);
}

void	print_line(char *name, t_pixel p0, t_pixel p1)
{
	printf("pixel %s\n", name);
	print_pix("p0 ", p0);
	print_pix("p1 ", p1);
}

void	print_matrix(char *name, t_matrix m)
{
	printf("mat %s\n", name);
	printf("%f %f %f \n", m[0][0], m[0][1], m[0][2]);
	printf("%f %f %f \n", m[1][0], m[1][1], m[1][2]);
	printf("%f %f %f \n", m[2][0], m[2][1], m[2][2]);
}

void	print_map(char *name, t_map map)
{
	printf("%s\n", name);
	printf("x max %d , y max %d \n", map.max_x, map.max_y);
	int x = 0, y = 0;
	t_point p;
		printf("Z\n");
	while(x < map.max_x )
	{
		while (y < map.max_y )
		{
			p = ft_point(&map, x, y);
			printf("%f ", p.r.z);
			y++;
		}
		x++;
		printf("\n");
		y = 0;
	}
	x = 0, y = 0;
	printf("COLOR\n");
	while(x < map.max_x)
	{
		while (y < map.max_y )
		{
			p = ft_point(&map, x, y);
			printf("%d ", p.color);
			y++;
		}
		x++;
		printf("\n");
		y = 0;
	}
}

void	print_cam(char *name, t_cam cam)
{
	printf("cam %s\n", name);
	print_vec3("taslation", cam.t);
	printf("angles: a %f b %f c %f \n", cam.a, cam.b, cam.c);
	print_matrix("rotation", cam.rot);
	printf("focal %f\n", cam.focal);
	printf("scale %f\n", cam.scale);
	printf("sh %f\n", cam.sh);
	printf("offx %f\n", cam.offx);
	printf("offy %f\n", cam.offy);
	print_matrix("affin ", cam.affin);
	print_matrix("look ", cam.look);
}

void	ft_axis(t_img img, t_map *map, t_cam cam)
{
	t_point p0;
	t_point p1;

	p0.r = (t_vec3){0,0,0};
	p0.color = 0x00FF0000;
	p1.r = (t_vec3){10,0,0}; // ROJO +X
	p1.color = 0x00FF0000; 
	projection(img, cam.look, cam.t, p0, p1);
	p0.color = 0x0000FF00;
	p1.r = (t_vec3){0,10,0}; // VERDE +Y
	projection(img, cam.look, cam.t, p0, p1);
	p0.color = 0x000000FF;
	p1.r = (t_vec3){0,0,10}; // AZUL +Z
	projection(img, cam.look, cam.t, p0, p1);
}