/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:45:43 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/24 15:57:16 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        write(2, "Usage: ./so_long <map.ber>\n", 28);
        return (1);
    }

    // Inicializar el juego
    init_game(&game, argv[1]); // Carga mapa, inicializa MinilibX, y estructura

    // Renderizar el mapa inicial (función a implementar más tarde)
    draw_map(&game);

    // Comenzar el bucle de eventos
    mlx_loop(game.mlx);

    return (0);
}


/* int main()
{
    void *mlx;
    void *win;
	
	//initialize MinilibX
    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
    if (!win)
        return (1);
    mlx_loop(mlx);
    return (0);
}
 */