/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:39 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/27 11:44:44 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, const char *map_file)
{
	// Cargar el mapa
	game->map = load_map(map_file);
	if(!game->map || !validate_map(game->map))
	{
		write(2, "Error: invalid map\n", 19);
		exit(1);
	}

	// Determinar dimensiones del mapa
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);

	// Inicializar MinilibX
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        write(2, "Error: Failed to initialize MinilibX\n", 37);
        exit(1); // Salir si hay error
    }

	// Crear una ventana con el tamaño del mapa
    game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
                               game->map_height * TILE_SIZE, "so_long");
    if (!game->win)
    {
        write(2, "Error: Failed to create window\n", 31);
        exit(1); // Salir si hay error
    }
	// Cargar los sprites
	load_sprites(game);

	// Dibujar el mapa
	draw_map(game);

	// Mensaje de depuración para confirmar que todo está bien
	write(1, "Game initialized successfully!\n", 31);

	// Configurar hooks de eventos (teclado, etc.)
	//mlx_hook(game->win, 17, 0, close_game, game); // Cerrar la ventana con la X
	//mlx_key_hook(game->win, handle_keypress, game);

	// Mantener la ventana abierta
	mlx_loop(game->mlx);
}

void	load_sprites(t_game *game)
{
	game->images.wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &game->map_width, &game->map_height);
	game->images.empty = mlx_xpm_file_to_image(game->mlx, "sprites/empty.xpm", &game->map_width, &game->map_height);
	game->images.player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->map_width, &game->map_height);
	game->images.coin = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm", &game->map_width, &game->map_height);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &game->map_width, &game->map_height);

	// Verifica que se cargaron correctamente
	if (!game->images.player || !game->images.wall || !game->images.empty || !game->images.coin || !game->images.exit)
	{
		perror("Error cargando los sprites");
		exit(EXIT_FAILURE);
	}
}
