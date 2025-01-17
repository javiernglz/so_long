/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:39 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/17 16:34:07 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, const char *map_file)
{
	game->map = load_map(map_file);
	if(!game->map || !validate_map(game->map))
	{
		write(2, "Error: invalid map\n", 19);
		exit(1);
	}

	// Inicializar MinilibX
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        write(2, "Error: Failed to initialize MinilibX\n", 37);
        exit(1); // Salir si hay error
    }

	// Crear una ventana con el tamaño del mapa
    game->win = mlx_new_window(game->mlx, game->map_width * 32,
                               game->map_height * 32, "so_long");
    if (!game->win)
    {
        write(2, "Error: Failed to create window\n", 31);
        exit(1); // Salir si hay error
    }
}