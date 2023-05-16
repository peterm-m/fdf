
#include "fdf.h"

void	print_vec3(char *name, t_vec3 v)
{
	printf("%s x %f y %f z %f \n", name, v.x, v.y, v.z);
}

void	print_ivec2(char *name, t_ivec2 v)
{
	printf("%s x %d y %d \n", name, v.x, v.y);
}

void	print_base(char *name, t_base3 base)
{
	printf("%s\n", name);
	print_vec3("e1", base.e1);
	print_vec3("e2", base.e2);
	print_vec3("e3", base.e3);
}

void	print_map(char *name, t_map map)
{
	printf("%s\n", name);
	printf("x max %d , y max %d \n", map.max_x, map.max_y );
	int x = 0, y = 0;
	t_point p;
	while(x < map.max_x)
	{
		while (y < map.max_y)
		{
			p = ft_point(&map, x, y);
			printf("r x %d y %d z %d color %d /n",p.r.x ,p.r.y, p.r.z, p.color);
			y++;
		}
		x++;
		y = 0;
	}
}

void	print_cam(char *name, t_cam cam)
{
	printf("%s\n", name);
	print_vec3("Camera pos", cam.pos);
	print_base("Base camera", cam.base);
	printf("focal %f\n", cam.focal);
}