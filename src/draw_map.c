/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:52:16 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/27 11:55:22 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_wall_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->images.wall, x * TILE_SIZE, y * TILE_SIZE);
}

void	insert_void_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->images.empty, (x) * TILE_SIZE, (y) * TILE_SIZE);
}

void	insert_player_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->images.player, (x) * TILE_SIZE, (y) * TILE_SIZE);
	game->player_pos_x = x;
	game->player_pos_y = y;
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i]) // Recorre cada fila del mapa
	{
		j = 0;
		while (game->map[i][j]) // Recorre cada columna de la fila
		{
			if (game->map[i][j] == '1') // Si es un muro
				insert_wall_img(game, j, i);
			else if (game->map[i][j] == '0') // Si es espacio vacío
				insert_void_img(game, j, i);
			else if (game->map[i][j] == 'P') // Si es el jugador
				insert_player_img(game, j, i);
			else if (game->map[i][j] == 'C') // Si es un coin
				mlx_put_image_to_window(game->mlx, game->win,
					game->images.coin, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E') // casilla exit
				mlx_put_image_to_window(game->mlx, game->win,
					game->images.exit, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

