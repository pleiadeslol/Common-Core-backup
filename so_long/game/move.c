/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:36:59 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/02 23:54:54 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

int	move_player(int keycode, void *mlx_ptr)
{
	t_mlx *mlx = mlx_ptr;
	t_point cur;
	int	x;
	int y;

	cur = find_cur(mlx->map);
	x = cur.x;
	y = cur.y;
	if (keycode == UP)
	{
		mlx->map[x][y] = '0';
		mlx->map[x][y - 1] = 'P';
	}
	return(0);
}
