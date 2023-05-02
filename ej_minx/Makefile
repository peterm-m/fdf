CC = gcc
SRC = minXej2.c
OBJ = $(SRC:%.c=%.o)
NAME = minXej2

FLAGS =  -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -L../minilibx_macos $(FLAGS) $(OBJ)  -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror  -O3 -c $< -o $@

