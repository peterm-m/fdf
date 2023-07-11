/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:32:20 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/11 21:34:04 by pedromar         ###   ########.fr       */
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

#  define KEY_ESC	65307
#  define KEY_Q	113
#  define KEY_E	101
#  define KEY_W	119
#  define KEY_S	115
#  define KEY_A	97
#  define KEY_D	100
#  define KEY_U	117
#  define KEY_O	111
#  define KEY_I	105
#  define KEY_K	107
#  define KEY_J	106
#  define KEY_L	108
#  define KEY_F	102
#  define KEY_G	103
#  define KEY_B	98
#  define KEY_N	110
#  define KEY_R	114
#  define KEY_T	116
#  define KEY_Z	122
#  define KEY_X	120
#  define KEY_C	99
#  define KEY_V	118
#  define ANG_RESTORE	48

# else

#  define KEY_Q	12
#  define KEY_W	13
#  define KEY_E	14
#  define KEY_R	15
#  define KEY_T	17
#  define KEY_Y	16
#  define KEY_U	32
#  define KEY_I	34
#  define KEY_O	31
#  define KEY_P	35
#  define KEY_A	0
#  define KEY_S	1
#  define KEY_D	2
#  define KEY_F	3
#  define KEY_G	5
#  define KEY_H	4
#  define KEY_J	38
#  define KEY_K	40
#  define KEY_L	37
#  define KEY_Z	6
#  define KEY_X	7
#  define KEY_C	8
#  define KEY_V	9
#  define KEY_B	11
#  define KEY_N	45
#  define KEY_M	46

#  define KEY_1	18
#  define KEY_2	19
#  define KEY_3	20
#  define KEY_4	21
#  define KEY_5	23
#  define KEY_6	22
#  define KEY_7	26
#  define KEY_8	28
#  define KEY_9	25
#  define KEY_0	29

#  define KEY_SPACE	49

#  define KEY_NPAD_0	82
#  define KEY_NPAD_1	83
#  define KEY_NPAD_2	84
#  define KEY_NPAD_3	85
#  define KEY_NPAD_4	86
#  define KEY_NPAD_5	87
#  define KEY_NPAD_6	88
#  define KEY_NPAD_7	89
#  define KEY_NPAD_8	91
#  define KEY_NPAD_9	92

#  define KEY_LEFT	123
#  define KEY_DOWN	125
#  define KEY_RIGHT	124
#  define KEY_UP	126

#  define MOUSE_LEFT	1
#  define MOUSE_RIGHT	2
#  define MOUSE_CENTER	3
#  define MOUSE_ROLL_DOWN	4
#  define MOUSE_ROLL_UP	5

#  define KEY_ESC 53

# endif

# define VIEW_POS_DX	1
# define VIEW_POS_DY	1
# define VIEW_POS_DZ	1

# define VIEW_ROT_DX	1
# define VIEW_ROT_DY	1
# define VIEW_ROT_DZ	1

# define MODEL_POS_DX	1
# define MODEL_POS_DY	1
# define MODEL_POS_DZ	1

# define MODEL_ROT_DX	1
# define MODEL_ROT_DY	1
# define MODEL_ROT_DZ	1

# define PROJ_MAX_DX	1
# define PROJ_MAX_DY	1
# define PROJ_MAX_DZ	1

# define PROJ_MIN_DX	1
# define PROJ_MIN_DY	1
# define PROJ_MIN_DZ	1

# define PROJ_TYPE_PROJ	0
# define PROJ_TYPE_ORTHO	1
# define PROJ_TYPE_PROJSYM	2
# define PROJ_TYPE_ORTHOSYM	3

#endif
