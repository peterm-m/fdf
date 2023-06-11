NAME = fdf

SRC_DIR := src

SRCS = \
	  vector/vector2.c\
	  vector/vector2_utils.c\
	  vector/matrix2.c\
	  vector/vector3.c\
	  vector/vector3_utils.c\
	  vector/matrix3.c\
	  vector/vector4.c\
	  vector/vector4_utils.c\
	  vector/matrix4.c\
	  vector/print_vector.c\
	  vector/print_matrix.c\
	  mlx_utils.c\
	  projectors.c\
	  camera.c\
	  render.c\
	  maps.c\
	  color.c\
	  color_utils.c\
	  plot_utils.c\
	  plot_map.c\
	  controls.c\
	  fdf.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

CC = gcc
DIR_DUP = mkdir -p $(@D)
CLEANER = rm -rf

UNAME := $(shell uname)

INCLUDE_FT =  -I../lib_basic/include 
DIR_FT = ../lib_basic

ifeq ($(UNAME), Linux)
 DIR_MLX = ../minilibx-linux
 INCLUDE_MLX = -I ../minilibx-linux
 MLX_FLAGS = -lXext -lX11 
 KEYS = -D KEYS_LINUX
else 
 DIR_MLX = ../minilibx_macos
 INCLUDE_MLX = -I ../minilibx_macos
 MLX_FLAGS = -framework OpenGL -framework AppKit
 KEYS = -D KEYS_MAC
endif

LIBS = -lft -lm $(MLX_FLAGS) -lmlx 
LIB_DIR = -L $(DIR_MLX) -L $(DIR_FT)
INCLUDES = -I./include $(INCLUDE_MLX) $(INCLUDE_FT)


FLAGS = -Wall -Wextra -Werror -O3
CCFLAGS =-Wall -Wextra  -O3 -fsanitize=address -g3

all: $(NAME)

$(NAME): libft mlx $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIB_DIR) $(LIBS) $(KEYS)
	$(info CREATED $(NAME))

libft:
	$(MAKE) -C $(DIR_FT)

mlx:
	$(MAKE) -C $(DIR_MLX)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES) $(KEYS)
	$(info CREATED $@)

clean:
	$(CLEANER) $(OBJS)
	$(MAKE) -C $(DIR_FT) clean
	$(MAKE) -C $(DIR_MLX) clean

fclean: clean 
	$(CLEANER) $(NAME)
	$(MAKE) -C $(DIR_FT) fclean
	$(MAKE) -C $(DIR_MLX) clean	

re:
	$(MAKE) fclean
	$(MAKE) all
