/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:22:40 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/26 21:29:17 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

char *get_next_line(int fd)
{
    static char buffer[1024];
    char *line;
    int bytes_read;

    line = malloc(1024);
    if (!line)
        return (NULL);
    bytes_read = read(fd, buffer, 1024);
    if (bytes_read <= 0)
    {
        free(line);
        return (NULL);
    }
    buffer[bytes_read] = '\0';
    strcpy(line, buffer);
    return (line);
}
