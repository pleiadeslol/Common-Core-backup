/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:36:59 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:25:09 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
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

void	handle_enemy(t_mlx *mlx, t_point p, t_point enemy)
{
	int	x;
	int	y;

	x = enemy.x;
	y = enemy.y;
	if (mlx->map[y + p.y][x + p.x] == '1' ||
			mlx->map[y + p.y][x + p.x] == 'C' ||
			mlx->map[y + p.y][x + p.x] == 'E')
		return ;
	if (mlx->map[y + p.y][x + p.x] == 'P')
		exit_mlx(mlx);
	mlx->map[y][x] = '0';
	mlx->map[y + p.y][x + p.x] = 'X';
}

void	move_enemy(t_mlx *mlx)
{
	t_point	enemy;
	int		dir;

	enemy = find_enemy(mlx->map);
	dir = rand() % 4;
	if (dir == 0)
		handle_enemy(mlx, (t_point){1, 0}, enemy);
	else if (dir == 1)
		handle_enemy(mlx, (t_point){-1, 0}, enemy);
	else if (dir == 2)
		handle_enemy(mlx, (t_point){0, 1}, enemy);
	else if (dir == 3)
		handle_enemy(mlx, (t_point){0, -1}, enemy);
}

void	handle_action(t_mlx *mlx, t_collec c, t_point p, t_point pos)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (mlx->map[y + p.y][x + p.x] == '1' || mlx->map[y + p.y][x + p.x] == 'X'
		|| (mlx->map[y + p.y][x + p.x] == 'E' && c.count != c.req_c))
		return ;
	if (mlx->map[y + p.y][x + p.x] == 'E' && c.count == c.req_c)
		exit_mlx(mlx);
	if (mlx->map[y + p.y][x + p.x] == 'C')
	{
		c.count++;
		if (c.count == c.req_c)
			mlx->img->exit = mlx_xpm_img(mlx->ptr, "textures/exit_1.xpm");
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
	player_dir(keycode, mlx, c, cur);
	return (0);
}
