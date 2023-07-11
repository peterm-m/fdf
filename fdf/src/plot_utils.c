/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:07:51 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/11 21:06:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_img *img, int x, int y, int c)
{
	char	*dst;

	if (x > 0 && y > 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *) dst = c;
	}
}

void	ft_plot_line(t_img *img, t_line l)
{
	while (l.i-- != 0)
	{
		ft_put_pixel(img, l.x0, l.y0, set_rgba(l.c));
		l.x1 -= l.dx;
		if (l.x1 < 0)
		{
			l.x1 += l.dm;
			l.x0 += l.sx;
		}
		l.y1 -= l.dy;
		if (l.y1 < 0)
		{
			l.y1 += l.dm;
			l.y0 += l.sy;
		}
		l.z1 -= l.dz;
		if (l.z1 < 0)
		{
			l.z1 += l.dm;
			l.z0 += l.sz;
		}
		l.c = ft_addv4(l.c, l.dc);
	}
}
