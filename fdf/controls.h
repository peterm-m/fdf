/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:32:20 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/18 20:32:44 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# if defined KEYS_LINUX
// general
#  define F_ESC 53
/*
* camera control
*/

// traslation 
#  define Q_ZPLUS 113
#  define E_ZMIN 101
#  define W_XPLUS 119
#  define S_XMIN 115
#  define A_YPLUS 97
#  define D_YMIN 100

// rotation
#  define U_APLUS 117
#  define O_AMIN 111
#  define I_BPLUS 105
#  define K_BMIN 107
#  define J_CPLUS 106
#  define L_CMIN 108
// focal
#  define F_FOCPLUS 102
#  define G_FOCMIN 103
// scale
#  define B_SCALEPLUS 98
#  define N_SCALEMIN 110
// shear
#  define R_SHPLUS 114
#  define T_SHMIN 116
// offset 
#  define Z_OFFXPLUS 122
#  define X_OFFXMIN 120
#  define C_OFFYPLUS 99
#  define V_OFFYMIN 118

# else
// general
#  define F_ESC 53

/*
* camera control
*/

// traslation 
#  define Q_ZPLUS 12
#  define E_ZMIN 14
#  define W_XPLUS 13
#  define S_XMIN 1
#  define A_YPLUS 0
#  define D_YMIN 2

// rotation
#  define U_APLUS 32
#  define O_AMIN 31
#  define I_BPLUS 34
#  define K_BMIN 40
#  define J_CPLUS 38
#  define L_CMIN 37
// focal
#  define F_FOCPLUS 3
#  define G_FOCMIN 5
// scale
#  define B_SCALEPLUS 11
#  define N_SCALEMIN 45
// shear
#  define R_SHPLUS 15
#  define T_SHMIN 17
// offset 
#  define Z_OFFXPLUS 6
#  define X_OFFXMIN 7
#  define C_OFFYPLUS 8
#  define V_OFFYMIN 9
# endif

# define STEP_X 1
# define STEP_Y 1
# define STEP_Z 1

# define STEP_A 2
# define STEP_B 2
# define STEP_C 2

#endif