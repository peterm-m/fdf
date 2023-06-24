/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:07:26 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/24 15:16:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix2	*new_matrix2(void )
{
	t_matrix2	*new;

	new = (t_matrix2 *)malloc(sizeof(t_matrix2));
	if (!new)
		return (NULL);
	ft_setrow2(new, (t_vec2){1, 0}, 0);
	ft_setrow2(new, (t_vec2){0, 1}, 1);
	return (new);
}
