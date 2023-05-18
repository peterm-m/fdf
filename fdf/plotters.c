/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:07:51 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/18 20:46:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x <= img.w && y <= img.h)
	{
		dst = img.addr + (y * img.size_line + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	ft_plot_line(t_img *img, t_pixel r0, t_pixel r1)
{
	t_ivec2	dr;
	int		err;

	dr.x = abs(r0.r.x - r1.r.x);
	dr.y = -abs(r0.r.y - r1.r.y);
	err = dr.x + dr.y;
	while (1)
	{
		ft_put_pixel(*img, r0.r.x, r0.r.y, r0.color);
		if ((r0.r.x == r1.r.x) && (r0.r.y == r1.r.y))
			break ;
		if (2 * err >= dr.y)
		{
			err = err + dr.y;
			r0.r.x = r0.r.x + (r1.r.x - r0.r.x) / abs(r1.r.x - r0.r.x);
		}
		if (2 * err <= dr.x)
		{
			err = err + dr.x;
			r0.r.y = r0.r.y + (r1.r.y - r0.r.y) / abs(r1.r.y - r0.r.y);
		}
	}
}

void	ft_plot_circle(t_img *img, int color, int rad, t_ivec2 r0)
{
	t_ivec2	r;
	int		err;

	r.x = -rad;
	r.y = 0;
	err = 2 - 2 * rad;
	while (1)
	{
		ft_put_pixel(*img, r0.x - r.x, r0.y + r.y, color);
		ft_put_pixel(*img, r0.x - r.y, r0.y - r.x, color);
		ft_put_pixel(*img, r0.x + r.x, r0.y - r.y, color);
		ft_put_pixel(*img, r0.x + r.y, r0.y + r.x, color);
		rad = err;
		if (rad <= r.y)
			err += ++r.y * 2 + 1;
		if (rad > r.x || err > r.y)
			err += ++r.x * 2 + 1;
		if (r.x > 0)
			break ;
	}
}
