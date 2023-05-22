/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:06:18 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/22 19:27:37 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	ft_program(int h, int w, char *str)
{
	void	*mlx_ptr;
	void	*win;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		exit(EXIT_FAILURE);
	win = mlx_new_window(mlx_ptr, w, h, str);
	if (!win)
		exit(EXIT_FAILURE);
	return ((t_win){mlx_ptr, win, w, h});
}

int	ft_end(t_render *r)
{
	if (r)
	{
		if (r->map)
		{
			if (r->map->z)
				free(r->map->z);
			if (r->map->color)
				free(r->map->color);
			free(r->map);
		}
		if (r->cam)
			free(r->cam);
		if (r->img)
		{
			mlx_destroy_image((r->img->win).mlx, r->img->ptr);
			mlx_destroy_window((r->img->win).mlx, (r->img->win).win);
			free(r->img);
		}
		free(r);
	}
	exit(EXIT_SUCCESS);
}

t_img	*ft_image(t_win win, int w, int h)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->win = win;
	img->ptr = mlx_new_image(win.mlx, w, h);
	if (!img->ptr)
		exit(EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->ptr, &(img->bpp),
			&(img->size_line), &(img->endian));
	img->w = w;
	img->h = h;
	return (img);
}
