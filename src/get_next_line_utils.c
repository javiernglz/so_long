/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:27:40 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/26 21:27:42 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(const char *s) {
    size_t len = 0;
    while (s[len])
        len++;
    return len;
}

char *ft_strdup(const char *s1) {
    char *copy = malloc(ft_strlen(s1) + 1);
    if (!copy)
        return NULL;
    strcpy(copy, s1);
    return copy;
}

char *ft_strjoin(char const *s1, char const *s2) {
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *joined = malloc(len1 + len2 + 1);
    if (!joined)
        return NULL;
    strcpy(joined, s1);
    strcpy(joined + len1, s2);
    return joined;
}
