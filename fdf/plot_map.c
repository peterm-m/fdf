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

void	projection(t_img img, t_matrix look, t_vec3 t, t_point p0, t_point p1)
{
	t_vec3	v0;
	t_vec3	v1;
	t_pixel	pix0;
	t_pixel	pix1;
	
	v0 = ft_traslation(p0.r, t);
	v0 = ft_bymat(&v0, look);
	pix0.r = (t_ivec2){(int)v0.x +DEFAULT_WINX/2, (int)v0.y+DEFAULT_WINY/2};
	pix0.color = p0.color;
	v1 = ft_traslation(p1.r, t);
	v1 = ft_bymat(&v1, look);
	pix1.r = (t_ivec2){(int)v1.x +DEFAULT_WINX/2, (int)v1.y +DEFAULT_WINY/2};
	pix1.color = p1.color;
	ft_plot_line(&img, pix0, pix1);
}

void	ft_plot_map(t_img img, t_map *map, t_cam cam)
{
	int		x;
	int		y;

	ft_axis(img, map, cam);
	x = 0;
	while (x < map->max_x -1)
	{
		y = 0;
		while (y < map->max_y -1)
		{
			projection(img, cam.look, cam.t, ft_point(map, x, y), ft_point(map, x, y + 1));
			projection(img, cam.look, cam.t, ft_point(map, x, y), ft_point(map, x + 1, y));
			y++;
		}
		projection(img, cam.look, cam.t, ft_point(map, x, y), ft_point(map, x + 1, map->max_y -1));
		x++;
	}
	y = 0;
	while (y < map->max_y -1)
	{
		projection(img, cam.look, cam.t,ft_point(map, map->max_x -1, y), ft_point(map, map->max_x -1, y + 1));
		y++;
	}
}
