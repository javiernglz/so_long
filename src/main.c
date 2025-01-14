/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:45:43 by frnavarr          #+#    #+#             */
/*   Updated: 2025/01/15 00:38:35 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
    void *mlx;
    void *win;
	
	//initialize MinilibX
    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
    if (!win)
        return (1);
    mlx_loop(mlx);
    return (0);
}
