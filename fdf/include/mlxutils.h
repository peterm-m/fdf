/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:25:28 by pedro             #+#    #+#             */
/*   Updated: 2023/05/22 17:45:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXUTILS_H
# define MLXUTILS_H

# include "fdf.h"

/*
* win struc: mlx X11 connection management.
*/
typedef struct s_win {
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_win;

/*
* default values mlx utils
*/
# define DEFAULT_WINX 512
# define DEFAULT_WINY 512
# define DEFAULT_IMGSIZX DEFAULT_WINX
# define DEFAULT_IMGSIZY DEFAULT_WINY

t_win	ft_program(int h, int w, char *str);

#endif