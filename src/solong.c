/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:40:42 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/07 11:24:30 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	error_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	arrow_keys(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (keycode == UP_KEY)
		move_player(game, -1, 0); // Arriba
	else if (keycode == LEFT_KEY)
		move_player(game, 0, -1); // Izq
	else if (keycode == DOWN_KEY)
		move_player(game, 1, 0); // Abajo
	else if (keycode == RIGHT_KEY)
		move_player(game, 0, 1); // Dcha
	return (0);
}

void render_move_count(t_game *game)
{
    char *move_str = ft_itoa(game->move_count);
    mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Movimientos: ");
    mlx_string_put(game->mlx, game->win, 110, 10, 0xFFFFFF, move_str);
    free(move_str);
}

void end_game(t_game *game)
{
    if (game->px == game->exit_x && game->py == game->exit_y)
    {
        game->map[game->exit_y][game->exit_x] = '0'; // Eliminar la salida del mapa
        mlx_put_image_to_window(game->mlx, game->win, game->images.empty_img, // Redibujar la casilla vacía
                                game->exit_x * TILE_SIZE, game->exit_y * TILE_SIZE);
		mlx_destroy_window(game->mlx, game->win);
        printf("¡Has ganado en %d movimientos!\n", game->move_count);
        exit(0);
    }
}

