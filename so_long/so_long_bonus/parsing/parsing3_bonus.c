/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:03:08 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:21:01 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/so_long_bonus.h"
#include "../ft_printf/ft_printf.h"

int	check_x(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'X')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_point	find_enemy(char **str)
{
	int		i;
	int		j;
	t_point	enemy;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'X')
			{
				enemy.x = j;
				enemy.y = i;
			}
			j++;
		}
		i++;
	}
	return (enemy);
}
