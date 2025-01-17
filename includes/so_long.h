/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:35:32 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/17 16:07:55 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define TILE_SIZE 32  // Tamaño de cada "tile" (cuadro)
#define WIN_WIDTH 640 // Ancho de la ventana
#define WIN_HEIGHT 480 // Alto de la ventana

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef
#include "mlx.h"
#endif

# define TILE_SIZE 32 // Tamaño de cada tile en píxeles

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_pos_x;
	int		player_pos_y;
	int		coins;
	int		moves;
}	t_game;

#endif
