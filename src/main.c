/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:45:43 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/26 23:15:34 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

// Declaración de la función get_next_line
char *get_next_line(int fd);

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
    {
        write(2, "Usage: ./so_long <map_file>\n", 27);
        return (1);
    }

    // Abrir el archivo pasado como argumento
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error opening file\n", 19);
        return (1);
    }

    // Leer las líneas del archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Imprimir cada línea
        free(line);          // Liberar la memoria de cada línea después de imprimirla
    }

    // Cerrar el archivo
    close(fd);

    return (0);
}


/* int main(int argc, char **argv)
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
 */

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