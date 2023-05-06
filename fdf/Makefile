CC = gcc
SRC = primitives.c\
	  bitmap_utils.c\
	  fdf.c
OBJ = $(SRC:%.c=%.o)
NAME = fdf

FLAGS =  -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -L../minilibx_macos $(FLAGS) $(OBJ)  -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror  -O3 -c $< -o $@
