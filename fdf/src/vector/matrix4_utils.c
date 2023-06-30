/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:26 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/30 20:53:59 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4	*new_matrix4(void )
{
	t_matrix4	*new;

	new = (t_matrix4 *)malloc(sizeof(t_matrix4));
	if (!new)
		return (NULL);
	ft_setrow4(new, (t_vec4){1, 0, 0, 0}, 0);
	ft_setrow4(new, (t_vec4){0, 1, 0, 0}, 1);
	ft_setrow4(new, (t_vec4){0, 0, 1, 0}, 2);
	ft_setrow4(new, (t_vec4){0, 0, 0, 1}, 3);
	return (new);
}
