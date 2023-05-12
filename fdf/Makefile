CC = gcc
SRC = primitives.c\
	  ft_parser.c\
	  bitmap_utils.c\
	  fdf.c
OBJ = $(SRC:%.c=%.o)
NAME = fdf

#LIB_DIR = -L ../minilibx-linux -L ../lib_basic
#LIBS = -lmlx -lXext -lX11 -lft
#INCLUDES = -I ../minilibx-linux -I../lib_basic/include
LIB_DIR = -L ../minilibx_macos -L ../lib_basic
LIBS = -lft -lmlx -lm -framework OpenGL -framework AppKit
INCLUDES  = -I../lib/include -I../lib_basic/include
FLAGS = -Wall -Wextra -Werror  -O3
CCFLAGS = -fsanitize=address -g3 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) $(LIB_DIR) $(LIBS) $(INCLUDES)

parser:
	gcc ft_parser.c -o parser  $(LIB_DIR) $(LIBS) $(INCLUDES)

%.o: %.c
	$(CC)  -c $< -o $@

