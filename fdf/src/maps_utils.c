/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:38:38 by pedro             #+#    #+#             */
/*   Updated: 2023/05/22 13:36:17 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_map *m)
{
	int		x;
	int		y;
	t_point	p;

	y = -1;
	ft_printf("MAP:\n");
	while (++y < m->nrow)
	{
		x = -1;
		while (++x < m->ncol)
		{
			p = point(m, x, y);
			ft_printf("%d|%d ", p.r.z, p.color);
		}
		ft_printf("\n");
	}
	ft_printf("nrow %d ncol %d\n", m->nrow, m->ncol);
}
