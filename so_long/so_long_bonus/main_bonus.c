/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:29 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:21:20 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long_bonus.h"
#include "headers/get_next_line.h"
#include "ft_printf/ft_printf.h"

int	main(int ac, char **av)
{
	int		fd;
	int		count;
	char	**str;
	t_mlx	mlx;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nNo such file or directory\n");
		return (1);
	}
	count = count_line(fd);
	close(fd);
	str = copy_str(av[1], count);
	if (errors(ac, av, str, count) == 0)
		return (0);
	mlx.map = str;
	mlx.moves = 0;
	mlx.dir = 2;
	draw_game(&mlx, count);
}
