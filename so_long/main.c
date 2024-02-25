/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:29 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/25 22:15:40 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include "headers/get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	int		count;
	char	**str;

	fd = open(av[1], O_RDONLY);
	count = count_line(fd);
	close(fd);
	str = copy_str(av[1], count);
	if (errors(ac, av, str, count) == 0)
		return (0);
	// draw_window();
	free_str(str);
	system("leaks a.out");
}
