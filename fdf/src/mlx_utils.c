/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:06:18 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/12 20:18:41 by pedromar         ###   ########.fr       */
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

int	ft_end_program(t_render *r)
{
	if (r)
	{
		if (r->map)
		{
			if (r->map->p)
				free(r->map->p);
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
