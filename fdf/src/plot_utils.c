/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:07:51 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 15:26:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_img *img, t_pixel *p)
{
	char	*dst;

	if (p->x > 0 && p->y > 0 && p->x < img->w && p->y < img->h)
	{
		dst = img->addr + (p->y * img->size_line + p->x * (img->bpp / 8));
		*(unsigned int *) dst = p->color;
	}
}

void	ft_plot_line(t_img *img, t_line *l)
{
//	int		err;

	//(t_ivec2){abs(r0.r.x - r1.r.x), -abs(r0.r.y - r1.r.y)}; /*#CONTINUE#*/
	//err = dr.x + dr.y;
	//get_gradient(&grad, &r0, &r1);
	//while (1)
	//{
	//	ft_put_pixel(*img, r0.r.x, r0.r.y, pixel_color(&grad, &r0, &r1));
	//	if ((r0.r.x == r1.r.x) && (r0.r.y == r1.r.y))
	//		break ;
	//	if (2 * err >= dr.y && (r1.r.x - r0.r.x) != 0)
	//	{
	//		err = err + dr.y;
	//		r0.r.x = r0.r.x + (r1.r.x - r0.r.x) / abs(r1.r.x - r0.r.x);
	//	}
	//	if (2 * err <= dr.x && (r1.r.y - r0.r.y) != 0)
	//	{
	//		err = err + dr.x;
	//		r0.r.y = r0.r.y + (r1.r.y - r0.r.y) / abs(r1.r.y - r0.r.y);
	//	}
	//}
}

void	ft_plot_circle(t_img *img, t_circle *c)
{
//	t_ivec2	r; /*#CONTINUE#*/
//	int		err;
//
//	r.x = -rad;
//	r.y = 0;
//	err = 2 - 2 * rad;
//	while (1)
//	{
//		ft_put_pixel(*img, r0.x - r.x, r0.y + r.y, color);
//		ft_put_pixel(*img, r0.x - r.y, r0.y - r.x, color);
//		ft_put_pixel(*img, r0.x + r.x, r0.y - r.y, color);
//		ft_put_pixel(*img, r0.x + r.y, r0.y + r.x, color);
//		rad = err;
//		if (rad <= r.y)
//			err += ++r.y * 2 + 1;
//		if (rad > r.x || err > r.y)
//			err += ++r.x * 2 + 1;
//		if (r.x > 0)
//			break ;
//	}
}

// void	ft_plot_axis(t_img *img, t_cam *cam)
// {
// 	t_point	p0;
// 	t_point	p1;
// 
// 	p0.r = (t_vec3){0, 0, 0};
// 	p0.color = 0x00FF0000;
// 	p1.r = (t_vec3){20, 0, 0};
// 	p1.color = 0x00FF0000;
// 	to_img(img, cam, p0, p1);
// 	p0.color = 0x00FF00FF;
// 	p1.r = (t_vec3){-20, 0, 0};
// 	p1.color = 0x00FF00FF;
// 	to_img(img, cam, p0, p1);
// 	p0.color = 0x0000FF00;
// 	p1.color = 0x0000FF00;
// 	p1.r = (t_vec3){0, 20, 0};
// 	to_img(img, cam, p0, p1);
// 	p0.color = 0x00FFFF00;
// 	p1.color = 0x00FFFF00;
// 	p1.r = (t_vec3){0, -20, 0};
// 	to_img(img, cam, p0, p1);
// 	p0.color = 0x000000FF;
// 	p1.color = 0x000000FF;
// 	p1.r = (t_vec3){0, 0, 20};
// 	to_img(img, cam, p0, p1);
// 	p0.color = 0x0000FFFF;
// 	p1.color = 0x0000FFFF;
// 	p1.r = (t_vec3){0, 0, -20};
// 	to_img(img, cam, p0, p1);
// }
// 
