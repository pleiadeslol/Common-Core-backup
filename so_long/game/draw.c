/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:49:13 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:00:29 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

void	mlx_image_win(t_mlx	*mlx, void	*map, int j, int i)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, map, j * 64, i * 64);
}

int	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
				mlx_image_win(mlx, mlx->img->wall, j, i);
			else if (mlx->map[i][j] == 'E')
				mlx_image_win(mlx, mlx->img->exit, j, i);
			else if (mlx->map[i][j] == '0')
				mlx_image_win(mlx, mlx->img->empty, j, i);
			else if (mlx->map[i][j] == 'C')
				mlx_image_win(mlx, mlx->img->collectible, j, i);
			else if (mlx->map[i][j] == 'P')
				mlx_image_win(mlx, mlx->img->player, j, i);
			j++;
		}
		i++;
	}
	return (0);
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
	map->wall = mlx_xpm_img(mlx->ptr, "textures/xpm/wall.xpm");
	map->empty = mlx_xpm_img(mlx->ptr, "textures/xpm/floor.xpm");
	map->collectible = mlx_xpm_img(mlx->ptr, "textures/xpm/c.xpm");
	map->player = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_down_0.xpm");
	map->exit = mlx_xpm_img(mlx->ptr, "textures/xpm/exit_0.xpm");
	mlx->img = map;
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
