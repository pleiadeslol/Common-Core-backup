/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:32:28 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:20:39 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include "../headers/get_next_line.h"
#include "../ft_printf/ft_printf.h"

int	av_errors(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("Error\nNo map in argument\n");
		return (0);
	}
	if (!check_ber(av[1]))
	{
		ft_printf("Error\nFile isn't a .ber file\n");
		return (0);
	}
	return (1);
}

int	map_errors1(char **str, int count)
{
	if (!check_len(str, count))
	{
		ft_printf("Error\nMap isn't rectangular\n");
		return (0);
	}
	if (!check_walls(str, count))
	{
		ft_printf("Error\nMap isn't surrounded by walls\n");
		return (0);
	}
	if (!check_char(str))
	{
		ft_printf("Error\nMap contains different characters");
		return (0);
	}
	return (1);
}

int	map_errors2(char **str)
{
	if (check_c(str) < 1)
	{
		ft_printf("Error\nMap doesn't contain a collectible\n");
		return (0);
	}
	if (check_x(str) < 1)
	{
		ft_printf("Error\nMap doesn't contain an enemy\n");
		return (0);
	}
	if (check_e(str) != 1 || check_p(str) != 1)
	{
		if (check_e(str) == 0)
			ft_printf("Error\nMap doesn't contain an exit\n");
		else if (check_e(str) > 1)
			ft_printf("Error\nMap contains more than one exit\n");
		else if (check_p(str) == 0)
			ft_printf("Error\nMap doesn't contain a starting position\n");
		else if (check_p(str) > 1)
			ft_printf("Error\nMap contains more than one starting position\n");
		return (0);
	}
	return (1);
}

int	map_errors3(char **av, char **str, int count)
{
	t_point	size;
	t_point	cur;
	char	**tab_c;
	char	**tab_e;

	cur = find_cur(str);
	size = find_size(str);
	tab_c = copy_str(av[1], count);
	tab_e = copy_str(av[1], count);
	if (flood_fill(tab_c, tab_e, size, cur) == 0)
		return (0);
	return (1);
}

int	errors(int ac, char **av, char **str, int count)
{
	if (av_errors(ac, av) == 0 || map_errors1(str, count) == 0
		|| map_errors2(str) == 0 || map_errors3(av, str, count) == 0)
		return (0);
	else
		return (1);
}
