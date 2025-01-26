# Definir el compilador y las banderas
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./minilibx/minilibx-linux

# Archivos fuente y objetos
SRCS = src/main.c src/init_game.c src/draw_map.c src/map.c src/get_next_line.c src/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

# Definir la ruta de MinilibX
MLX = ./minilibx/minilibx-linux/
MLX_FLAGS = -L$(MLX) -lmlx -lX11 -lXext -lm -lz

# Nombre del ejecutable
NAME = so_long

# Regla principal
all: $(NAME)

# Regla para generar el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

# Regla para limpiar los archivos objetos
clean:
	rm -f $(OBJS)

# Regla para limpiar todo (incluido el ejecutable)
fclean: clean
	rm -f $(NAME)

# Regla para hacer limpieza y luego compilar
re: fclean all

# Regla para generar las dependencias
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
