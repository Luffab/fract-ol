NAME = fractol

SRCS =  srcs/main.c \
        srcs/mandelbrot.c \
        srcs/fractol.c \
        srcs/colors.c \
        srcs/key_hook.c \
        srcs/julia.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_memcpy.c \
		srcs/ft_atoi.c \
		srcs/ft_atod.c \
		srcs/errors.c \
        
FLAGS = -Wall -Wextra -Werror -g2

HEADER_FILE = ./include

HEADERS =   $(HEADER_FILE)/fractol.h \

MLX_NAME = mlx/libmlx.a

OBJS = ${SRCS:.c=.o}

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re

$(NAME): $(OBJS) $(MLX_NAME)
	clang $(OBJS) $(MLX_NAME) -o $(NAME) -lm -framework OpenGL -framework AppKit

$(OBJS): %.o: %.c $(HEADERS)
	clang $(FLAGS) -I$(HEADER_FILE) -c $< -o $@


$(MLX_NAME):
	$(MAKE) -C mlx

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C mlx clean

fclean: clean
	rm -f $(NAME)

re: fclean all