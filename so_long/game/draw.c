/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:49:13 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/01 18:49:07 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

void	mlx_image_win(t_mlx	mlx, void	*map, int j, int i)
{
	mlx_put_image_to_window(mlx.ptr, mlx.win, map, j * 64, i * 64);
}

void	draw_map(char **str, t_map map, t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1')
				mlx_image_win(mlx, map.wall, j, i);
			else if (str[i][j] == 'E')
				mlx_image_win(mlx, map.exit, j, i);
			else if (str[i][j] == '0')
				mlx_image_win(mlx, map.empty, j, i);
			else if (str[i][j] == 'C')
				mlx_image_win(mlx, map.collectible, j, i);
			else if (str[i][j] == 'P')
				mlx_image_win(mlx, map.player, j, i);
			j++;
		}
		i++;
	}
}

void	*mlx_xpm_img(void *ptr, char *path, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(ptr, path, &x, &y);
	return(img);
}

void	free_draw(t_mlx mlx, t_map map)
{
	mlx_destroy_image(mlx.ptr, map.wall);
	mlx_destroy_image(mlx.ptr, map.empty);
	mlx_destroy_image(mlx.ptr, map.collectible);
	mlx_destroy_image(mlx.ptr, map.exit);
	mlx_destroy_image(mlx.ptr, map.player);
	mlx_destroy_window(mlx.ptr, mlx.win);
	free(mlx.ptr);
}

void	draw_game(char **str, int count)
{
	t_mlx	mlx;
	t_map	map;
	int		x;
	int		y;

	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		return ;
	mlx.win = mlx_new_window(mlx.ptr, (ft_strlen(str[0]) * 64),
			count * 64, "so_long");
	if (mlx.win == NULL)
		return ;
	map.wall = mlx_xpm_img(mlx.ptr, "textures/xpm/wall.xpm", x, y);
	map.empty = mlx_xpm_img(mlx.ptr, "textures/xpm/floor.xpm", x, y);
	map.collectible = mlx_xpm_img(mlx.ptr, "textures/xpm/c.xpm", x, y);
	map.player = mlx_xpm_img(mlx.ptr, "textures/xpm/cat_down_0.xpm", x, y);
	map.exit = mlx_xpm_img(mlx.ptr, "textures/xpm/exit_0.xpm", x, y);
	if (map.wall == NULL || map.empty == NULL)
		return ;
	draw_map(str, map, mlx);
	mlx_loop(mlx.ptr);
	free_draw(mlx, map);
	return ;
}
