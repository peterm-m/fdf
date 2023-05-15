/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 20:20:50 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	projection(t_img img, t_cam cam, t_point p0, t_point p1)
{
	t_vec3	v0;
	t_vec3	v1;
	t_ivec2	iv0;
	t_ivec2	iv1;
	float	pscalar;

	v0 = ft_sum(p0.r, ft_byscalar(cam.pos, -1.0));
	pscalar = ft_dot_product((cam.base).e1, v0);
	v0 = ft_sum(v0, ft_byscalar((cam.base).e1, -pscalar));
	iv0 = (t_ivec2){(int)ft_dot_product((cam.base).e2, v0) + DEFAULT_WINY / 2,
		(int)ft_dot_product((cam.base).e3, v0) * 100 + DEFAULT_WINX / 2};
	v1 = ft_sum(p1.r, ft_byscalar(cam.pos, -1.0));
	pscalar = ft_dot_product((cam.base).e1, v1);
	v1 = ft_sum(v1, ft_byscalar((cam.base).e1, -pscalar));
	iv1 = (t_ivec2){(int)ft_dot_product((cam.base).e2, v0) + DEFAULT_WINY / 2,
		(int)ft_dot_product((cam.base).e3, v1) * 100 + DEFAULT_WINX / 2};
	printf("iv0 x %d y %d \n", iv0.x, iv0.y);
	printf("iv1 x %d y %d \n", iv1.x, iv1.y);
	ft_plot_line(&img, 0x00FF0000, iv0, iv1);
}

void	ft_plot_map(t_img img, t_map *map, t_cam cam)
{
	int		x;
	int		y;

	x = 0;
	while (x < map->max_x -1)
	{
		y = 0;
		while (y < map->max_y -1)
		{
			projection(img, cam, ft_point(map, x, y), ft_point(map, x, y + 1));
			projection(img, cam, ft_point(map, x, y), ft_point(map, x + 1, y));
			y++;
		}
		projection(img, cam, ft_point(map, x, y), ft_point(map, x + 1, y));
		x++;
	}
	y = 0;
	while (y < map->max_y -1)
	{
		projection(img, cam, ft_point(map, x, y), ft_point(map, x, y + 1));
		y++;
	}
}
