/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 04:16:15 by pedro             #+#    #+#             */
/*   Updated: 2023/05/08 04:16:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# define BUFFER_ULL 64

# define F_ZERO       1
# define F_PLUS       2
# define F_LEFT       4
# define F_HASH       8
# define F_SPACE     16
# define F_PRECISION 32
# define F_UPPER    128
# define F_NEGATIVE 256

# define LEN_HH   1
# define LEN_H    2
# define LEN_LL   4
# define LEN_L    8
# define LEN_J   16
# define LEN_Z   32

typedef struct s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	length;
	unsigned int	base;
	unsigned int	inbuffer;
}	t_format;

#endif