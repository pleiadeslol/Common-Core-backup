/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:36:59 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/03 00:42:35 by rzarhoun         ###   ########.fr       */
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
	if (keycode == UP || keycode == W)
	{
		if (mlx->map[y - 1][x] == '1')
			return (0);
		mlx->map[y][x] = '0';
		mlx->map[y - 1][x] = 'P';
	}
	else if (keycode == DOWN || keycode == S)
	{
		if (mlx->map[y + 1][x] == '1')
			return (0);
		mlx->map[y][x] = '0';
		mlx->map[y + 1][x] = 'P';
	}
	else if (keycode == RIGHT || keycode == D)
	{
		if (mlx->map[y][x + 1] == '1')
			return (0);
		mlx->map[y][x] = '0';
		mlx->map[y][x + 1] = 'P';
	}
	else if (keycode == LEFT || keycode == A)
	{
		if (mlx->map[y][x - 1] == '1')
			return (0);
		mlx->map[y][x] = '0';
		mlx->map[y][x - 1] = 'P';
	}
	return(0);
}
