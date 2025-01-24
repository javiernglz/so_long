/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:35:32 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/24 13:16:32 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32  // Tamaño de cada "tile" (cuadro)
# define WIN_WIDTH 640 // Ancho de la ventana
# define WIN_HEIGHT 480 // Alto de la ventana
# define TILE_SIZE 64 // Tamaño de cada tile en píxeles

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h" // Include MinilibX

typedef struct s_images
{
	void	*wall;
	void	*empty;
	void	*player;
	void	*exit;
	void	*coin;

}	t_images;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_pos_x;
	int		player_pos_y;
	int		moves;
	void	*player_sprite;
	void	*wall_sprite;
	void	*coin_sprite;
	void	*exit_sprite;
	t_images    *images; // Estructura para almacenar los sprites

}	t_game;

void init_game(t_game *game, char *map_path);
void render_map(t_game *game);

#endif
