/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:49:13 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/28 18:19:12 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

void	draw_wall(char **str, int count)
{
	void    *mlx;
	void    *mlx_win;
	void	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	if (mlx == NULL)
		return ;
	mlx_win = mlx_new_window(mlx, (ft_strlen(str[0]) * 16), count * 16, "so_long");
	if (mlx_win == NULL)
		return;
	img = mlx_xpm_file_to_image(mlx, "draw/wall.xpm", &x, &y);
	if (img == NULL)
		return;
	int i = 0;
	int j;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img, j * 16, i * 16);
			j++;
		}		
		i++;
	}
	mlx_loop(mlx);
	// mlx_destroy_window(mlx, mlx_win);
	// free(mlx);
	return;
}