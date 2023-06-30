/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:26 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/30 20:54:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix3	*new_matrix3(void )
{
	t_matrix3	*new;

	new = (t_matrix3 *)malloc(sizeof(t_matrix3));
	if (!new)
		return (NULL);
	ft_setrow3(new, (t_vec3){1, 0, 0}, 0);
	ft_setrow3(new, (t_vec3){0, 1, 0}, 1);
	ft_setrow3(new, (t_vec3){0, 0, 1}, 2);
	return (new);
}
