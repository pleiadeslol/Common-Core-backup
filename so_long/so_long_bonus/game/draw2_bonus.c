/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:07:08 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:20:24 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

void	player_dir(int keycode, t_mlx *mlx, t_collec c, t_point cur)
{
	if (keycode == UP || keycode == W)
	{
		mlx->dir = 1;
		handle_action(mlx, c, (t_point){0, -1}, cur);
	}
	else if (keycode == DOWN || keycode == S)
	{
		mlx->dir = 2;
		handle_action(mlx, c, (t_point){0, 1}, cur);
	}
	else if (keycode == RIGHT || keycode == D)
	{
		mlx->dir = 3;
		handle_action(mlx, c, (t_point){1, 0}, cur);
	}
	else if (keycode == LEFT || keycode == A)
	{
		mlx->dir = 4;
		handle_action(mlx, c, (t_point){-1, 0}, cur);
	}
}

void	*mlx_xpm_img(void *ptr, char *path)
{
	void	*img;
	int		x;

	img = mlx_xpm_file_to_image(ptr, path, &x, &x);
	return (img);
}

void	get_img(t_mlx *mlx)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return ;
	map->wall = mlx_xpm_img(mlx->ptr, "textures/wall.xpm");
	map->empty = mlx_xpm_img(mlx->ptr, "textures/floor.xpm");
	map->collectible = mlx_xpm_img(mlx->ptr, "textures/c.xpm");
	map->enemy = mlx_xpm_img(mlx->ptr, "textures/enemy.xpm");
	map->exit = mlx_xpm_img(mlx->ptr, "textures/exit_0.xpm");
	mlx->img = map;
	player_sprites(map, mlx);
}

void	draw_game(t_mlx *mlx, int count)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return ;
	mlx->win = mlx_new_window(mlx->ptr, (ft_strlen(mlx->map[0]) * 64),
			count * 64, "so_long");
	if (mlx->win == NULL)
		return ;
	get_img(mlx);
	if (mlx->img->wall == NULL || mlx->img->empty == NULL)
		return ;
	mlx_loop_hook(mlx->ptr, &draw_map, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, &move_player, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, &exit_mlx, mlx);
	mlx_loop(mlx->ptr);
	free_game(mlx, mlx->img);
	return ;
}
