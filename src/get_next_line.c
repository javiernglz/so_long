/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:22:40 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/26 23:38:27 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 32

static char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = malloc((i + 2) * sizeof(char)); // +1 for \n and +1 for \0
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] != '\0' && str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_acumclean(char *acum)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (acum[i] != '\0' && acum[i] != '\n')
		i++;
	if (acum[i] == '\0')
	{
		free(acum);
		return (NULL);
	}
	new_line = malloc((ft_strlen(acum) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (acum[i] != '\0')
		new_line[j++] = acum[i++];
	new_line[j] = '\0';
	free(acum);
	return (new_line);
}

static char	*ft_acum(char *st_ac, char *tmp)
{
	char	*acum;

	acum = ft_strjoin(st_ac, tmp);
	free(st_ac);
	return (acum);
}

static char	*ft_get_piece(char *st_ac, int fd)
{
	char	*tmp;
	int		read_return;

	if (!st_ac)
		st_ac = malloc(1); // Inicializamos la acumulación como NULL
	read_return = 1;
	tmp = malloc(BUFFER_SIZE + 1); // Usamos un buffer temporal
	if (!tmp)
		return (NULL);
	while (read_return > 0)
	{
		read_return = read(fd, tmp, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_return] = '\0';
		st_ac = ft_acum(st_ac, tmp);
		if (ft_strchr(tmp, '\n'))  // Buscar el '\n' en el buffer
			break;
	}
	free(tmp);
	return (st_ac);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*st_acum;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st_acum = ft_get_piece(st_acum, fd);
	if (!st_acum)
		return (NULL);
	line = ft_get_line(st_acum);
	st_acum = ft_acumclean(st_acum);
	return (line);
}
