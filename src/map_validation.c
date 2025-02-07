/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:08:05 by frnavarr          #+#    #+#             */
/*   Updated: 2025/02/07 11:25:30 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_player_position(t_game *game)
{
	int		y;
	char	*pos;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		pos = ft_strchr(game->map[y], 'P');
		if (pos)
		{
			game->px = pos - game->map[y];
			game->py = y;
			return;
		}
		y++;
	}
	error_exit("Error: no se encontro la posicion del jugador.");
}

/* static bool	check_spaces(char *s, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (i > 0 && s[i] == '\n' && s[i - 1] == '\n')
		{
			printf("Error\nWrong map shape");
			free(s);
			return (false);
		}
		i++;
	}
	game->map = ft_split(s, '\n');
	return (true);
} */

static void item_counter(t_game *game)
{
    int	x;
	int	y;

    y = 0;
    while (y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_HEIGHT)
        {
            if (game->map[y][x] == 'C')
                game->coin++;
            else if (game->map[y][x] == 'P')
            {
                game->px = x;
                game->py = y;
                game->player_count++;
            }
            else if (game->map[y][x] == 'E')
                game->exit++;
            x++;
        }
        y++;
    }
}

static bool character_check(t_game *game)
{
    int	x;
	int	y;

    y = 0;
    while (y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_HEIGHT)
        {
            if (game->map[y][x] != '1' && game->map[y][x] != '0'
                && game->map[y][x] != 'P' && game->map[y][x] != 'C'
                && game->map[y][x] != 'E' && game->map[y][x] != 'X')
            {
                printf("Error\nThe map contains invalid characters\n");
                return (false);  // Devuelve false si carácter no válido
            }
            x++;
        }
        y++;
    }
    return (true);
}

bool	bonus_content_checker(t_game *game)
{
	game->coin = 0;
	game->player_count = 0;
	game->exit = 0;
	item_counter(game);
	if (character_check(game)
		&& game->coin > 0 && game->player_count == 1 && game->exit == 1)
		return (true);
	if (game->coin == 0)
		printf("Error\nWrong number of coins\n");
	if (game->player_count != 1)
		printf("Error\nWrong number of characters\n");
	if (game->exit != 1)
		printf("Error\nWrong number of exits\n");
	return (false);
}