/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:22:23 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/04 17:47:54 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_game *game, int delta_y, int delta_x)
{
    int new_y = game->player.y + delta_y;
    int new_x = game->player.x + delta_x;

    // Verificar si el jugador toca al enemigo
    if (game->map[new_y][new_x] == 'X')
    {
        mlx_put_image_to_window(game->mlx, game->win, game->images.empty_img, 
                                game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
        game->map[game->player.y][game->player.x] = '0'; // Eliminar al jugador del mapa
        game->map[new_y][new_x] = '0'; // Eliminar el enemigo de su posición
        mlx_put_image_to_window(game->mlx, game->win, game->images.empty_img, 
                                new_x * TILE_SIZE, new_y * TILE_SIZE); // Redibujar casilla vacía
        printf("¡Has sido eliminado por el enemigo!\n");
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }

    // Movimiento normal
    if (game->map[new_y][new_x] != '1')
    {
        mlx_put_image_to_window(game->mlx, game->win, game->images.empty_img, 
                                game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
        game->map[game->player.y][game->player.x] = '0';
        game->map[new_y][new_x] = 'P';

        if (delta_y == -1) game->images.player_img = game->images.player_up_img;
        else if (delta_y == 1) game->images.player_img = game->images.player_abajo_img;
        else if (delta_x == -1) game->images.player_img = game->images.player_izq_img;
        else if (delta_x == 1) game->images.player_img = game->images.player_dcha_img;

        mlx_put_image_to_window(game->mlx, game->win, game->images.player_img, 
                                new_x * TILE_SIZE, new_y * TILE_SIZE);

        game->move_count++;
        render_move_count(game);
        game->player.y = new_y;
        game->player.x = new_x;
    }
}
