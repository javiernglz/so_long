#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "../libft/libft.h"

#define MAP_WIDTH 29
#define MAP_HEIGHT 10
#define TILE_SIZE 64

#define ESC_KEY 65307
#define UP_KEY 119    // W
#define LEFT_KEY 97   // A
#define DOWN_KEY 115  // S
#define RIGHT_KEY 100 // D

// Estructura para almacenar sprites
typedef struct s_images {
    void	*wall_img;
    void	*empty_img;
    void	*player_img;
	void	*player_abajo_img;
	void	*player_izq_img;
	void	*player_dcha_img;
	void	*player_up_img;
    void	*exit_img;
	void	*coin_img;
} t_images;

typedef struct s_game {
    void		*mlx;
    void		*win;
    char		**map;
    t_images	images;
	int			move_count;
	int			moves;
	int			exit;
	int			exit_x;
	int			exit_y;
	int			coin;
	int			px;
	int			py;
	int			player_count;
} t_game;

void	error_exit(char *message);
char	**load_map(const char *filename);
void	load_sprites(void *mlx, t_images *images);
void	draw_map(void *mlx, void *window, t_images *images, char **map);
void	move_player(t_game *game, int delta_y, int delta_x);
void	first_player_position(t_game *game);
int		arrow_keys(int keycode, t_game *game);
void	render_move_count(t_game *game);
void 	end_game(t_game *game);
void	load_sprites_elements(void *mlx, t_images *images);
void	load_sprites_players(void *mlx, t_images *images);

#endif
