/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:29:51 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/07 12:28:36 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char **copy_map(const t_game *game) {
    char **copy = malloc(sizeof(char *) * game->height);
    int i = 0;

    if (!copy)
        return NULL;
    while (i < game->height) {
        copy[i] = ft_strdup(game->map[i]);
        if (!copy[i]) {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return NULL;
        }
		printf("Mapa Copia [%d]: %s\n", i, copy[i]); // DEBUG
        i++;
    }
    return copy;
}

static void free_map(char **map, int height)
{
    int i = 0;

    while (i < height) {
        free(map[i]);
        i++;
    }
    free(map);
}

/* Algoritmo de Flood Fill usando recursión */
static void flood_fill(char **map, int row, int col, int height, int width)
{
    if (row < 0 || row >= height || col < 0 || col >= width)
        return;
    if (map[row][col] != '0' && map[row][col] != 'C' && map[row][col] != 'E' && map[row][col] != 'P')
        return;

    map[row][col] = 'F';  // Marcar como visitado

    printf("Expandiendo en (%d, %d)\n", row, col); // DEBUG
    flood_fill(map, row + 1, col, height, width); // Abajo
    flood_fill(map, row - 1, col, height, width); // Arriba
    flood_fill(map, row, col + 1, height, width); // Derecha
    flood_fill(map, row, col - 1, height, width); // Izquierda
}
bool check_road(t_game *game)
{
    char **map_copy = copy_map(game);
    int row, col, reachable = 0;

    if (!map_copy) {
        fprintf(stderr, "Error: no se pudo asignar memoria para la copia del mapa\n");
        return false;
    }

    // Ejecutar flood desde la posición inicial del jugador
    flood_fill(map_copy, game->py, game->px, game->height, game->width);

    row = 0;
    while (row < game->height) {
        col = 0;
        while (col < game->width)
		{
            if ((game->map[row][col] == 'C' || game->map[row][col] == 'E') &&
                map_copy[row][col] == 'F')
            {
                reachable++;
            }
            col++;
        }
        row++;
    }

    free_map(map_copy, game->height);

    if (reachable == game->coin + 1)
        return true;
    
    printf("Error\nNo possible path\n");
    return false;
}
