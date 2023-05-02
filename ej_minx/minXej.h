

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define F_ESC 53

# define CL_RED 1 << 3
# define CL_GREEN 1 << 2
# define CL_BLUE 1 << 1
# define CL_OO 1 << 0

# define CL_MASK_OO 0xFF << 24
# define CL_MASK_RED 0xFF << 16
# define CL_MASK_GREEN 0xFF <<  8
# define CL_MASK_BLUE 0xFF <<  0

# define CL_POS_OO 24
# define CL_POS_RED 16
# define CL_POS_GREEN 8
# define CL_POS_BLUE 0

typedef struct s_pix {
	int	x;
	int	y;
} t_pix;

typedef struct s_vec {
	int	x;
	int	y;
	int	z;
} t_vec;

typedef struct s_win {
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_win;

typedef struct	s_img {
	t_win	win;
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}				t_img;

#endif