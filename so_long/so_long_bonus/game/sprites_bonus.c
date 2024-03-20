/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 03:20:08 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:20:30 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

void	player_sprites(t_map *player, t_mlx *mlx)
{
	player->player_up[0] = mlx_xpm_img(mlx->ptr, "textures/cat_up_0.xpm");
	player->player_up[1] = mlx_xpm_img(mlx->ptr, "textures/cat_up_1.xpm");
	player->player_up[2] = mlx_xpm_img(mlx->ptr, "textures/cat_up_2.xpm");
	player->player_up[3] = mlx_xpm_img(mlx->ptr, "textures/cat_up_3.xpm");
	player->player_down[0] = mlx_xpm_img(mlx->ptr, "textures/cat_down_0.xpm");
	player->player_down[1] = mlx_xpm_img(mlx->ptr, "textures/cat_down_1.xpm");
	player->player_down[2] = mlx_xpm_img(mlx->ptr, "textures/cat_down_2.xpm");
	player->player_down[3] = mlx_xpm_img(mlx->ptr, "textures/cat_down_3.xpm");
	player->player_right[0] = mlx_xpm_img(mlx->ptr, "textures/cat_right_0.xpm");
	player->player_right[1] = mlx_xpm_img(mlx->ptr, "textures/cat_right_1.xpm");
	player->player_right[2] = mlx_xpm_img(mlx->ptr, "textures/cat_right_2.xpm");
	player->player_right[3] = mlx_xpm_img(mlx->ptr, "textures/cat_right_3.xpm");
	player->player_left[0] = mlx_xpm_img(mlx->ptr, "textures/cat_left_0.xpm");
	player->player_left[1] = mlx_xpm_img(mlx->ptr, "textures/cat_left_1.xpm");
	player->player_left[2] = mlx_xpm_img(mlx->ptr, "textures/cat_left_2.xpm");
	player->player_left[3] = mlx_xpm_img(mlx->ptr, "textures/cat_left_3.xpm");
}
