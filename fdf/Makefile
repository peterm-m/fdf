NAME = fdf

SRC = plotters.c\
	  vector.c\
	  vector_utils.c\
	  camera.c\
	  camera_utils.c\
	  maps.c\
	  mlx_utils.c\
	  color.c\
	  plot_map.c\
	  controls.c\
	  debug.c\
	  fdf.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

CLEANER = rm -rf

#### linux
LIB_DIR = -L ../minilibx-linux -L ../lib_basic
LIBS = -lmlx -lm -lXext -lX11 -lft
INCLUDES = -I ../minilibx-linux -I../lib_basic/include
KEYS = -D KEYS_LINUX

#### mac
#LIB_DIR = -L ../minilibx_macos -L ../lib_basic
#LIBS = -lft -lmlx -lm -framework OpenGL -framework AppKit
#INCLUDES  = -I ../minilibx_macos -I ../lib_basic/include/
#KEYS = -D KEYS_MAC

FLAGS = -Wall -Wextra -Werror -O3
CCFLAGS =-Wall -Wextra -Werror -O3 -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) $(INCLUDES) $(LIB_DIR) $(LIBS) $(KEYS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES) $(KEYS)

clean:
	$(CLEANER) $(OBJ)

fclean: clean 
	$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

