CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./minilibx/minilibx-linux
SRCS = src/main.c src/init_game.c src/draw_map.c
OBJS = $(SRCS:.c=.o)
MLX = ./minilibx/minilibx-linux/
MLX_FLAGS = -L$(MLX) -lmlx -lX11 -lXext -lm -lz
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
