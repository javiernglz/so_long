/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:19:32 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/26 22:21:43 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//function that load the map
//almacenar array de strings char **
/* char **load_map(const char *filename)
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
} */

char **load_map(const char *filename)
{
    int fd;
    int i = 0;
    char *line;
    char **map;

    // Abrir el archivo
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return NULL; // No se pudo abrir el archivo
    }

    // Reservar espacio para el mapa
    map = malloc(sizeof(char *) * (MAX_MAP_LINES + 1));  // Añadí +1 para el NULL final
    if (!map)
    {
        perror("Error al asignar memoria para el mapa");
        close(fd);
        return NULL; // Error en la asignación de memoria
    }

    // Leer las líneas y almacenarlas en el mapa
    while ((line = get_next_line(fd)))
    {
        map[i] = line;
        i++;
        if (i >= MAX_MAP_LINES)
        {
            write(2, "Error: Mapa demasiado grande\n", 28);
            free(map);  // Liberar memoria previamente asignada
            close(fd);
            return NULL;
        }
    }
    map[i] = NULL;  // Añadir NULL al final para terminar el array de cadenas

    // Cerrar el archivo
    close(fd);

    return map;
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
    size_t i, j;
    size_t row_length;  // Ahora row_length es de tipo size_t
    int player_count = 0, exit_count = 0, coin_count = 0;

    // Verificar las paredes del contorno (superior, inferior, izquierdo, derecho)
    for (i = 0; map[i]; i++)
    {
        row_length = strlen(map[i]);  // Guardamos la longitud de la fila

        // Verificar que todas las filas tengan la misma longitud
        if (i > 0 && strlen(map[i]) != row_length)
        {
            return 0;  // Mapa no rectangular
        }

        for (j = 0; j < row_length; j++)  // Cambié el bucle de j a row_length
        {
            // Verificar las paredes en el contorno
            if (i == 0 || map[i + 1] == NULL || j == 0 || map[i][j + 1] == '\0' || i == (size_t)strlen(map[i]) - 1)
            {
                if (map[i][j] != '1') // Las paredes deben ser '1'
                {
                    printf("Erroor en el contorno en la posición (%zu, %zu): %c\n", i, j, map[i][j]);
                    return 0; // Mapa inválido
                }
            }
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
        return 0; // Mapa inválido si no hay un jugador, una salida y al menos una moneda
    }

    return 1; // Mapa válido
}
