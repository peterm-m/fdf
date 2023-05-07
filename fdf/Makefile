CC = gcc
SRC = primitives.c\
	  ft_parser.c\
	  bitmap_utils.c\
	  fdf.c
OBJ = $(SRC:%.c=%.o)
NAME = fdf

FLAGS =  -I../lib_basic -lmlx -lm -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -L../minilibx_macos $(FLAGS) $(OBJ)  -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror  -O3 -c $< -o $@

