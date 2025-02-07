/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:40:42 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/07 00:32:40 by frnavarr         ###   ########.fr       */
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

/* void	move_player(t_game *game, int delta_y, int delta_x)
{
	int new_y = game->player_y + delta_y;
	int new_x = game->player_x + delta_x;

	// Verifico que la casilla destino no sea pared
	if (game->map[new_y][new_x] != '1')
	{
		// Redibujar el suelo en la posición anterior del jugador
		mlx_put_image_to_window(game->mlx, game->win, game->images.empty_img, 
								game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
		// Actualizo mapa: cambiar la posición del jugador
		game->map[game->player_y][game->player_x] = '0'; // Casilla vacía
		game->map[new_y][new_x] = 'P'; // Nueva posición del jugador

		// Actualizo coordenadas del jugador
		game->player_y = new_y;
		game->player_x = new_x;

		// Cambiar sprite del jugador según la dirección del movimiento
		if (delta_y == -1)      // Arriba
			game->images.player_img = game->images.player_up_img;
		else if (delta_y == 1)  // Abajo
			game->images.player_img = game->images.player_abajo_img;
		else if (delta_x == -1) // Izquierda
			game->images.player_img = game->images.player_izq_img;
		else if (delta_x == 1)  // Derecha
			game->images.player_img = game->images.player_dcha_img;

		mlx_put_image_to_window(game->mlx, game->win, game->images.player_img, 
                        new_x * TILE_SIZE, new_y * TILE_SIZE);
		// Incrementar el contador de movimientos
		game->move_count++;
		// Mostrar el número de movimientos en pantalla
		display_moves(game);
	}
} */



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

