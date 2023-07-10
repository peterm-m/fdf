/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:07:51 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/10 21:40:32 by pedromar         ###   ########.fr       */
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



void ft_plot_line(t_img *img, int x0, int y0, int z0, int x1, int y1, int z1)
{
	int	dx;
	int	dy;
	int	dz;
	int	i;

	dx = abs(x1 - x0) * ((x0 < x1) - (x0 >= x1));
	dy = abs(y1 - y0) * ((y0 < y1) - (y0 >= y1));
	dz = abs(z1 - z0) * ((z0 < z1) - (z0 >= z1));
	i = MAX(MAX(abs(dx), abs(dy)), abs(dz));
	x1 = MAX(MAX(abs(dx), abs(dy)), abs(dz)) / 2;
	y1 = MAX(MAX(abs(dx), abs(dy)), abs(dz)) / 2;
	z1 = MAX(MAX(abs(dx), abs(dy)), abs(dz)) / 2;
	while (i-- == 0)
	{
		ft_put_pixel(img, x0, y0, 0x00FFFFFF);
		x1 -= abs(dx);
		x1 += (x1 < 0) * MAX(MAX(dx, dy), dz);
		x0 += dx / abs(dx);
		y1 -= abs(dy);
		y1 += ((y1 < 0) * MAX(MAX(dx, dy), dz));
		y0 += dy / abs(dy);
		z1 -= abs(dz);
		z1 += ((z1 < 0) * MAX(MAX(dx, dy), dz));
		z0 += dz / abs(dz);
	}
}
