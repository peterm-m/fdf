NAME = fdf

SRC_DIR := src

SRCS = \
	  vector/addm.c\
	  vector/ident.c\
	  vector/addv.c\
	  vector/cross.c\
	  vector/divmf.c\
	  vector/divv2.c\
	  vector/dotv.c\
	  vector/eqv.c\
	  vector/len.c\
	  vector/lensqr.c\
	  vector/linearcomb.c\
	  vector/mat.c\
	  vector/mulmf.c\
	  vector/mulmm.c\
	  vector/mulmv.c\
	  vector/mulv.c\
	  vector/mulvf.c\
	  vector/printm.c\
	  vector/printv.c\
	  vector/subm.c\
	  vector/subv.c\
	  vector/vec.c\
	  vector/transpose.c\
	  trasformations/lookat.c\
	  trasformations/ortho.c\
	  trasformations/perspective.c\
	  trasformations/rotation.c\
	  trasformations/scale.c\
	  trasformations/traslation.c\
	  render/camera.c\
	  render/maps.c\
	  render/render.c\
	  controls/controls.c\
	  controls/keys.c\
	  controls/mouse.c\
	  mlx_utils.c\
	  plot_utils.c\
	  plot_map.c\
	  fdf.c\
	  color/color.c

.SILENT:

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
CCFLAGS =-Wall -Wextra  -Werror -O3 -fsanitize=address -g3

all: $(NAME)

$(NAME): libft mlx $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIB_DIR) $(LIBS) $(KEYS)
	$(info CREATED $(NAME))

libft:
	@$(MAKE) -C $(DIR_FT)

mlx:
	echo make $(DIR_MLX)
	@$(MAKE) -C $(DIR_MLX) 2>/dev/null

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
