/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:13:15 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/10 11:29:09 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_keys(int keycode, t_vars *vars)
{
	if (keycode == KEY_RIGHT)
		vars->player.pos.x += 1;
	else if (keycode == KEY_LEFT)
		vars->player.pos.x -= 1;
	else if (keycode == KEY_UP)
		vars->player.pos.y -= 1;
	else if (keycode == KEY_DOWN)
		vars->player.pos.y += 1;
	return (0);
}