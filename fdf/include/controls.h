/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:32:20 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/10 08:29:30 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

int		key_manager(int key, t_render *render);
int		mouse_manager(int buttom, int x, int y, t_render *render);

void	view_manager(int key, t_render *r);
void	model_manger(int key, t_render *r);
void	projection_manager(int key, t_render *r);
void	key_scale(void );

# if defined KEYS_LINUX

#  define KEY_ESC 65307
#  define KEY_Q 113
#  define KEY_E 101
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_U 117
#  define KEY_O 111
#  define KEY_I 105
#  define KEY_K 107
#  define KEY_J 106
#  define KEY_L 108
#  define KEY_F 102
#  define KEY_G 103
#  define KEY_B 98
#  define KEY_N 110
#  define KEY_R 114
#  define KEY_T 116
#  define KEY_Z 122
#  define KEY_X 120
#  define KEY_C 99
#  define KEY_V 118
#  define ANG_RESTORE 48

# else

#  define KEY_ESC 53
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_E 14
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_U 32
#  define KEY_O 31
#  define KEY_I 34
#  define KEY_K 40
#  define KEY_J 38
#  define KEY_L 37
#  define KEY_F 3
#  define KEY_G 5
#  define KEY_B 11
#  define KEY_N 45
#  define KEY_R 15
#  define KEY_T 17
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_C 8
#  define KEY_V 9
#  define ANG_RESTORE 48

# endif

# define STEP_X 1
# define STEP_Y 1
# define STEP_Z 1

# define STEP_A 0.1
# define STEP_B 0.1
# define STEP_C 0.1

# define STEP_FOC 1
# define MIN_FOC 0.1

# define STEP_SCALE 0.1
# define MIN_SCALE 0.1

# define STEP_SH 0.1
# define MIN_SH 0

# define STEP_OFFX 5
# define STEP_OFFY 5

#endif
