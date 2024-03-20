/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:49:13 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:20:14 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

void	mlx_image_win(t_mlx	*mlx, void	*map, int j, int i)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, map, j * 64, i * 64);
}

void	player_pos(t_mlx *mlx, void *player[4], int i, int j)
{
	static int	count_player;

	mlx_image_win(mlx, player[count_player], j, i);
	count_player++;
	if (count_player > 3)
		count_player = 0;
}

void	animate_player(t_mlx *mlx, int i, int j)
{
	if (mlx->dir == 1)
		player_pos(mlx, mlx->img->player_up, i, j);
	else if (mlx->dir == 2)
		player_pos(mlx, mlx->img->player_down, i, j);
	else if (mlx->dir == 3)
		player_pos(mlx, mlx->img->player_right, i, j);
	else if (mlx->dir == 4)
		player_pos(mlx, mlx->img->player_left, i, j);
}

void	map_img_win(t_mlx *mlx, int i, int j)
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
		animate_player(mlx, i, j);
	else if (mlx->map[i][j] == 'X')
		mlx_image_win(mlx, mlx->img->enemy, j, i);
}

int	draw_map(t_mlx *mlx)
{
	int		i;
	int		j;
	char	*move;
	char	*move_num;

	i = 0;
	move_num = ft_itoa(mlx->moves);
	move = ft_strjoin(ft_strdup("moves :"), move_num);
	usleep(100500);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			map_img_win(mlx, i, j);
			j++;
		}
		i++;
	}
	move_enemy(mlx);
	mlx_string_put(mlx->ptr, mlx->win, 32, 12, 0x00FFFFFF, move);
	free(move_num);
	free(move);
	return (0);
}
