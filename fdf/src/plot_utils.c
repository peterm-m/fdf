/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:07:51 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/15 21:23:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_img *img, t_pixel *p)
{
	char	*dst;

	if (p->x > 0 && p->y > 0 && p->x < img->w && p->y < img->h)
	{
		dst = img->addr + (p->y * img->size_line + p->x * (img->bpp / 8));
		*(unsigned int *) dst = 0;
	}
}

void	ft_plot_line(t_img *img, t_line *l)
{
	while (1)
	{
		ft_put_pixel(img, &(l->p0));
		if ((l->p0.x == l->p1.x) && (l->p0.y == l->p1.y))
			break ;
		if (2 * l->err >= l->dy)
		{
			l->err += l->dy;
			l->p0.x += l->sx;
		}
		if (2 * l->err <= l->dx)
		{
			l->err += l->dx;
			l->p0.y += l->sy;
		}
	}
}

//void	ft_plot_circle(t_img *img, t_circle *c)
//{
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
//}

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
