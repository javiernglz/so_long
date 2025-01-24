/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:52:16 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/24 13:30:55 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_wall_img(t_game *game, int *x, int *y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->images->wall, (*x) * TILE_SIZE, (*y) * TILE_SIZE);
}

void	insert_void_img(t_game *game, int *x, int *y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->images->empty, (*x) * TILE_SIZE, (*y) * TILE_SIZE);
}

void	insert_player_img(t_game *game, int *x, int *y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->images->player, (*x) * TILE_SIZE, (*y) * TILE_SIZE);
}