/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:20:04 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/07 11:26:15 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites_elements(void *mlx, t_images *images)
{
	images->wall_img = mlx_xpm_file_to_image(mlx, "./sprites/wall.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!images->wall_img)
	{
		error_exit("Error al cargar la imagen de la pared");
	}
	images->empty_img = mlx_xpm_file_to_image(mlx, "./sprites/empty.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!images->empty_img)
	{
		error_exit("Error al cargar la imagen del camino");
	}
	images->exit_img = mlx_xpm_file_to_image(mlx, "./sprites/exit.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!images->exit_img)
	{
		error_exit("Error al cargar la imagen de la salida");
	}
	images->coin_img = mlx_xpm_file_to_image(mlx, "./sprites/coin.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!images->coin_img)
	{
		error_exit("Error al cargar la imagen del coleccionable");
	}
}

void	load_sprites_players(void *mlx,t_images *images)
{
	images->player_up_img = mlx_xpm_file_to_image(mlx, "./sprites/player_up.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	images->player_abajo_img = mlx_xpm_file_to_image(mlx, "./sprites/player_abajo.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	images->player_izq_img = mlx_xpm_file_to_image(mlx, "./sprites/player_izq.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	images->player_dcha_img = mlx_xpm_file_to_image(mlx, "./sprites/player_dcha.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!images->player_dcha_img || !images->player_izq_img || !images->player_abajo_img || !images->player_up_img)
		error_exit("Error al cargar la imagen del jugador");

	images->player_img = images->player_up_img;
}

void	draw_map(void *mlx, void *window, t_images *images, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, window, images->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx, window, images->empty_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx, window, images->empty_img, x * TILE_SIZE, y * TILE_SIZE);
				mlx_put_image_to_window(mlx, window, images->player_img, x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, window, images->exit_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx, window, images->empty_img, x * TILE_SIZE, y * TILE_SIZE);
				mlx_put_image_to_window(mlx, window, images->coin_img, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

char	**load_map(const char *filename)
{
	FILE *fd;
	int i;
	char **map_lines;
	char *line = NULL;
	size_t len;
	ssize_t read;

	fd = fopen(filename, "r");
	if (!fd)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
/* 	if (!check_spaces(line, game))
		exit(EXIT_FAILURE);
	free(line); */
	map_lines = malloc(sizeof(char *) * MAP_HEIGHT);
	if (!map_lines)
	{
		perror("Error de memoria");
		exit(EXIT_FAILURE);
	}
	i = 0;
	len = 0;
	while ((read = getline(&line, &len, fd)) != -1 && i < MAP_HEIGHT)
	{
		map_lines[i] = ft_strdup(line);
		if (!map_lines[i])
		{
			perror("Error de memoria al duplicar linea");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	fclose(fd);
	free(line);
	if (i < 0)
		error_exit("Error, el mapa tiene menos lineas de las esperadas.");
	return (map_lines);
}