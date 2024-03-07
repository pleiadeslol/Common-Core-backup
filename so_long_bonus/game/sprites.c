/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 03:20:08 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/07 03:35:23 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

void	player_sprites(t_map *player)
{
	player->player_up[0] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_up_0.xpm");
	player->player_up[1] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_up_1.xpm");
	player->player_up[2] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_up_2.xpm");
	player->player_up[3] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_up_3.xpm");
	player->player_down[0] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_down_0.xpm");
	player->player_down[1] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_down_1.xpm");
	player->player_down[2] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_down_2.xpm");
	player->player_down[3] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_down_3.xpm");
	player->player_right[0] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_right_0.xpm");
	player->player_right[1] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_right_1.xpm");
	player->player_right[2] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_right_2.xpm");
	player->player_right[3] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_right_3.xpm");
	player->player_left[0] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_left_0.xpm");
	player->player_left[1] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_left_1.xpm");
	player->player_left[2] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_left_2.xpm");
	player->player_left[3] = mlx_xpm_img(mlx->ptr, "textures/xpm/cat_left_3.xpm");
}

void	enemy_sprites(t_map *enemy)
{
	enemy->enemy[0] = mlx_xpm_img(mlx->ptr, "textures/xpm/enemy_0.xpm");
	enemy->enemy[1] = mlx_xpm_img(mlx->ptr, "textures/xpm/enemy_1.xpm");
}

void	exit_sprites(t_map *exit)
{
	exit->exit[0] = mlx_xpm_img(mlx->ptr, "textures/xpm/exit_0.xpm");
	exit->exit[1] = mlx_xpm_img(mlx->ptr, "textures/xpm/exit_1.xpm");
	exit->exit[2] = mlx_xpm_img(mlx->ptr, "textures/xpm/exit_2.xpm");
	exit->exit[3] = mlx_xpm_img(mlx->ptr, "textures/xpm/exit_3.xpm");
}
