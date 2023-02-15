
NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra
#-fsanitize=address -g

SRC = ft_fractol.c \
	julia.c \
	complex_math.c \
	hooks.c \
	mandelbrot.c \
	params.c \
	burning.c \


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
