NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -I./src -I./src_b -I./minilibx/minilibx-linux -I./includes -I./libft
RM = rm -f
LIBFT = libft/libft.a
SRCS = src/solong.c src/load_map.c src/map_validation.c src/movements.c src/main.c
OBJS = $(SRCS:.c=.o)

# Librerías para el enlazado
LIBS = $(LIBFT) -L./minilibx/minilibx-linux -lmlx -lX11 -lXext -lm

all: libft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -C libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) src_b/*.o
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus