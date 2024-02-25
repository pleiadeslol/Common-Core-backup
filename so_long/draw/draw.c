/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:49:13 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/25 19:08:41 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"

void    draw_window()
{
	void    *mlx;
	void    *mlx_win;

	mlx = mlx_init();
	if (mlx == NULL)
		return ;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	// mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}