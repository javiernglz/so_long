/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:35:32 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/27 11:44:26 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 640 // Ancho de la ventana
# define WIN_HEIGHT 480 // Alto de la ventana
# define TILE_SIZE 64 // Tamaño de cada tile en píxeles
# define MAX_MAP_LINES 100

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h" // Include MinilibX

typedef struct s_images {
	void	*wall;
	void	*empty;
	void	*player;
	void	*coin;
	void	*exit;
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
	t_images    images; // Estructura para almacenar los sprites
}	t_game;

void	load_sprites(t_game *game);
void	init_game(t_game *game, const char *map_file);
void	draw_map(t_game *game);
char 	*get_next_line(int fd);
char 	**load_map(const char *map_file);
int 	validate_map(char **map);
int     ft_strlen(const char *str);
char    *ft_strdup(const char *s1);
char    *ft_strjoin(char const *s1, char const *s2);
int     search_nline(const char *s, int c);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strchr(const char *s, int c);

#endif
