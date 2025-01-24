/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:39 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/24 15:55:54 by frnavarr         ###   ########.fr       */
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
    game->win = mlx_new_window(game->mlx, game->map_width * 64,
                               game->map_height * 64, "so_long");
    if (!game->win)
    {
        write(2, "Error: Failed to create window\n", 31);
        exit(1); // Salir si hay error
    }
}

void	load_sprites(t_game *game)
{
	int	width;
	int	height;

	// Carga cada sprite en la estructura
	game->player_sprite = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &width, &height);
	game->wall_sprite = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &width, &height);
	game->coin_sprite = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm", &width, &height);
	game->exit_sprite = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &width, &height);

	// Verifica que se cargaron correctamente
	if (!game->player_sprite || !game->wall_sprite || !game->coin_sprite || !game->exit_sprite)
	{
		perror("Error cargando los sprites");
		exit(EXIT_FAILURE);
	}
}
