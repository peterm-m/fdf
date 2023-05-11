NAME = libftprintf.a
SRC = ft_printf.c\
	ft_vaprintf.c\
	ft_switch_conversion.c\
	ft_int_conversion.c\
	ft_char_conversion.c\
	ft_double_conversion.c\
	ft_print_buffer.c

BONUS = ft_printf_bonus.c\
	ft_vaprintf_bonus.c\
	ft_switch_conversion_bonus.c\
	ft_int_conversion_bonus.c\
	ft_char_conversion_bonus.c\
	ft_double_conversion_bonus.c\
	ft_print_buffer_bonus.c

OBJ = $(SRC:%.c=%.o)

OBJB = $(BONUS:%.c=%.o)

CC      = gcc
CFLAGSS = -c -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGSS) $(SRC)
	$(AR) $(NAME) $(OBJ)

B = .
bonus: $(B)
	$(CC) -c $(BONUS)
	$(AR) $(NAME) $(OBJB)

fclean:
	@rm -f $(NAME) $(OBJ) $(OBJB)

clean:
	@rm -f $(OBJ) $(OBJB)

re: fclean all

.PHONY: fclean all clean re bonus

so:
	$(CC) -nostartfiles  -fPIC $(CFLAGSS) $(SRC)
	gcc -nostartfiles  -shared -o libft.so $(OBJ)
