/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:36:59 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/03 21:24:05 by rzarhoun         ###   ########.fr       */
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
	int	count;
	int	collec;

	cur = find_cur(mlx->map);
	x = cur.x;
	y = cur.y;
	count = 0;
	collec = check_c(mlx->map);
	if (keycode == UP || keycode == W)
	{
		if (mlx->map[y - 1][x] == '1')
			return (0);
		if (mlx->map[y - 1][x] == 'C')
			count++;
		mlx->map[y][x] = '0';
		mlx->map[y - 1][x] = 'P';
	}
	else if (keycode == DOWN || keycode == S)
	{
		if (mlx->map[y + 1][x] == '1')
			return (0);
		if (mlx->map[y + 1][x] == 'C')
			count++;
		mlx->map[y][x] = '0';
		mlx->map[y + 1][x] = 'P';
	}
	else if (keycode == RIGHT || keycode == D)
	{
		if (mlx->map[y][x + 1] == '1')
			return (0);
		if (mlx->map[y][x + 1] == 'C')
			count++;
		mlx->map[y][x] = '0';
		mlx->map[y][x + 1] = 'P';
	}
	else if (keycode == LEFT || keycode == A)
	{
		if (mlx->map[y][x - 1] == '1')
			return (0);
		if (mlx->map[y][x - 1] == 'C')
			count++;
		mlx->map[y][x] = '0';
		mlx->map[y][x - 1] = 'P';
	}
	if (count == collec)
		mlx->img->exit = mlx_xpm_img(mlx->ptr, "textures/xpm/exit_3.xpm", x, y);
	return(0);
}
