/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:36:59 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/06 20:56:50 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include "../minilibx/mlx.h"

int	exit_mlx(void	*mlx)
{
	t_mlx	*mlx_ptr;

	mlx_ptr = mlx;
	free_game(mlx_ptr, mlx_ptr->img);
	exit(0);
}

void	handle_action(t_mlx *mlx, t_collec c, t_point p, t_point pos)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (mlx->map[y + p.y][x + p.x] == '1'
		|| (mlx->map[y + p.y][x + p.x] == 'E' && c.count != c.req_c))
		return ;
	if (mlx->map[y + p.y][x + p.x] == 'E' && c.count == c.req_c)
	{
		free_game(mlx, mlx->img);
		exit(0);
	}
	if (mlx->map[y + p.y][x + p.x] == 'C')
	{
		c.count++;
		if (c.count == c.req_c)
			mlx->img->exit = mlx_xpm_img(mlx->ptr,
					"textures/xpm/exit_3.xpm");
	}
	mlx->map[y][x] = '0';
	mlx->map[y + p.y][x + p.x] = 'P';
	mlx->moves++;
	ft_printf("Moves: %d\n", mlx->moves);
}

int	move_player(int keycode, void *mlx_ptr)
{
	t_mlx		*mlx;
	t_point		cur;
	t_collec	c;

	mlx = mlx_ptr;
	cur = find_cur(mlx->map);
	c.count = 0;
	c.req_c = check_c(mlx->map);
	if (keycode == ESC)
	{
		free_game(mlx, mlx->img);
		exit(0);
	}
	if (keycode == UP || keycode == W)
		handle_action(mlx, c, (t_point){0, -1}, cur);
	else if (keycode == DOWN || keycode == S)
		handle_action(mlx, c, (t_point){0, 1}, cur);
	else if (keycode == RIGHT || keycode == D)
		handle_action(mlx, c, (t_point){1, 0}, cur);
	else if (keycode == LEFT || keycode == A)
		handle_action(mlx, c, (t_point){-1, 0}, cur);
	return (0);
}
