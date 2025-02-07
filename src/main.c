/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:22:54 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/07 12:06:07 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;
	
	if (argc < 2)
	{
        printf("Uso: %s <mapa>\n", argv[0]);
        return (1);
    }
    game.mlx = mlx_init();
    game.map = load_map(argv[1]);

	if (!game.map)
	{
        printf("Error al cargar el mapa: %s\n", argv[1]);
        return (1); 
    }
    first_player_position(&game);
	if (!check_road(&game))
    exit(EXIT_FAILURE);

    game.images.player_img = game.images.player_abajo_img;
    game.win = mlx_new_window(game.mlx, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "So Long Game");

    load_sprites_elements(game.mlx, &game.images);
    load_sprites_players(game.mlx, &game.images);

    draw_map(game.mlx, game.win, &game.images, game.map);
    mlx_hook(game.win, 2, 1L << 0, arrow_keys, &game);

    mlx_loop(game.mlx);

    return (0);
}