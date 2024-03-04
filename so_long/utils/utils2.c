/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:57:19 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/04 21:59:47 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"
#include "../minilibx/mlx.h"

int	count_line(int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
			count++;
		free (line);
		line = get_next_line(fd);
	}
	free(line);
	return (count);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_point	find_cur(char **str)
{
	int		i;
	int		j;
	t_point	cur;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				cur.x = j;
				cur.y = i;
			}
			j++;
		}
		i++;
	}
	return (cur);
}

t_point	find_size(char **str)
{
	int		i;
	int		j;
	t_point	size;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		i++;
	}
	size.x = j;
	size.y = i;
	return (size);
}

void	free_game(t_mlx *mlx, t_map *map)
{
	mlx_destroy_image(mlx->ptr, map->wall);
	mlx_destroy_image(mlx->ptr, map->empty);
	mlx_destroy_image(mlx->ptr, map->collectible);
	mlx_destroy_image(mlx->ptr, map->exit);
	mlx_destroy_image(mlx->ptr, map->player);
	mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	free(mlx->img);
	free_str(mlx->map);
}
