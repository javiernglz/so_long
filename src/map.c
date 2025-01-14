

#include "so_long.h"
//function that load the map
char **load_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return NULL;
	//implementar get next line
}

//function that check if the map is correct

int validate_map(char **map)
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
}
