NAME = fdf

SRC = plotters.c\
	  vector.c\
	  camera.c\
	  maps.c\
	  mlx_utils.c\
	  color.c\
	  transformations.c\
	  plot_map.c\
	  fdf.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

CLEANER = rm -rf

#### linux
#LIB_DIR = -L ../minilibx-linux -L ../lib_basic
#LIBS = -lmlx -lXext -lX11 -lft
#INCLUDES = -I ../minilibx-linux -I../lib_basic/include

#### mac
LIB_DIR = -L ../minilibx_macos -L ../lib_basic
LIBS = -lft -lmlx -lm -framework OpenGL -framework AppKit
INCLUDES  = -I ../minilibx_macos -I ../lib_basic/include/

FLAGS = -Wall -Wextra -Werror -O3
CCFLAGS = -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) $(INCLUDES) $(LIB_DIR) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(INCLUDES)

clean:
	$(CLEANER) $(OBJ)

fclean: clean
	$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

