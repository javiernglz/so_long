/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:19:32 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/26 21:57:24 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//function that load the map
//almacenar array de strings char **
char **load_map(const char *filename)
{
	int	fd;
    int i;
    char *line;
    char **map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return NULL;
	map = malloc(sizeof(char *) * MAX_MAP_LINES);
    if (!map)
        return (NULL);
    i = 0;
    while ((line = get_next_line(fd)))
    {
        map[i] = line;
        i++;
    }
    close(fd);
    return (map);
}

//function that check if the map is correct

/* int validate_map(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            //NULL se usa para comprobar si un puntero es nulo, como en map[i + 1] == NULL (asegura que no estás fuera de las filas del mapa).
            //'\0' se usa para verificar el final de una cadena, como en map[i][j + 1] == '\0' (asegura que no estás fuera de los caracteres de una fila)
            if ((i == 0 || map[i + 1] == NULL || j == 0 || map[i][j + 1] == '\0') && map[i][j] != '1')
                return (0); //invalid map
            j++;
        }
        i++;
    }

    // Verify player, coins and exit
    int player_count = 0, exit_count = 0, coin_count = 0;
    for (i = 0; map[i]; i++)
    {
        for (j = 0; map[i][j]; j++)
        {
            if (map[i][j] == 'P')
                player_count++;
            else if (map[i][j] == 'E')
                exit_count++;
            else if (map[i][j] == 'C')
                coin_count++;
        }
    }
    if (player_count != 1 || exit_count != 1 || coin_count < 1)
        return (0);
    return (1); // valid map
} */

#include <stdio.h>
#include <string.h>

int validate_map(char **map)
{
    int i, j;
    int player_count = 0, exit_count = 0, coin_count = 0;

    // Verificar las paredes del contorno (superior, inferior, izquierdo, derecho)
    for (i = 0; map[i]; i++)
    {
        for (j = 0; map[i][j]; j++)
        {
            // Verificar la primera y última fila
            if (i == 0 || map[i + 1] == NULL)
            {
                if (map[i][j] != '1') // Las paredes deben ser '1' en las primeras y últimas filas
                {
                    printf("Error en el contorno en la posición (%d, %d): %c\n", i, j, map[i][j]);
                    return (0); // Mapa inválido
                }
            }
            if (map[i][j + 1] == '\0' && map[i][j] != '1')
            {
                printf("Error en el contorno en la posición (%d, %d): %c\n", i, j, map[i][j]);
                return (0); // Mapa inválido
            }
            // Verificar las primeras y últimas columnas de cada fila
            if (j == 0 || map[i][j + 1] == '\0')
            {
                if (map[i][j] != '1') // Las paredes deben ser '1' en las primeras y últimas columnas
                {
                    printf("Error en el contorno en la posición (%d, %d): %c\n", i, j, map[i][j]);
                    return (0); // Mapa inválido
                }
            }
        }
    }

    // Verificar que el mapa sea rectangular (todas las filas deben tener el mismo número de columnas)
    size_t	row_length = strlen(map[0]);
    for (i = 1; map[i]; i++)
    {
        if (strlen(map[i]) != row_length)
        {
            printf("Error: El mapa no es rectangular, diferencia en la fila %d\n", i);
            return 0; // Mapa no rectangular
        }
    }

    // Verificar la cantidad de P (jugador), E (salida) y C (monedas)
    for (i = 0; map[i]; i++)
    {
        for (j = 0; map[i][j]; j++)
        {
            if (map[i][j] == 'P') // Jugador
                player_count++;
            else if (map[i][j] == 'E') // Salida
                exit_count++;
            else if (map[i][j] == 'C') // Monedas
                coin_count++;
        }
    }

    if (player_count != 1 || exit_count != 1 || coin_count < 1)
    {
        printf("Error: El mapa debe tener un jugador ('P'), una salida ('E') y al menos una moneda ('C').\n");
        return (0); // Mapa inválido si no hay un jugador, una salida y al menos una moneda
    }

    return (1); // Mapa válido
}
