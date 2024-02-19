/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:29 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/18 20:51:20 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int i = 0;

	if (ac == 1)
	{
		printf("Error\nNo map in argument\n");
		return (0);
	}
	if (!check_ber(av[1]))
	{
		printf("Error\nFile isn't a .ber file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	char *line;
	int count = 0;
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(ft_strtrim(line, "\n")) != 0)
		{
			line = ft_strtrim(line, "\n");
			count++;
		}
	}
	char **str = malloc(sizeof(char **) * (count + 1));
	if (!str)
	{
		printf("Error\nError allocating!\n");
		return (0);
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	while ((str[i] = get_next_line(fd)))
	{
		if (ft_strlen(ft_strtrim(str[i], "\n")) != 0)
		{
			str[i] = ft_strtrim(str[i], "\n");
			i++;
		}
	}
	if (!check_len(str, count))
	{
		printf("Error\nMap isn't rectangular\n");
		return (0);
	}
	if (!check_walls(str))
	{
		printf("Error\nMap isn't surrounded by walls\n");
		return (0);
	}
	if (!check_char(str))
	{
		printf("Error\nMap contains different characters");
		return (0);
	}
	if (check_e(str) != 1)
	{
		if (check_e(str) == 0)
			printf("Error\nMap doesn't contain an exit\n");
		else
			printf("Error\nMap contains more than one exit\n");
		return (0);
	}
	if (check_c(str) < 1)
	{
		printf("Error\nMap doesn't contain a collectible\n");
		return (0);
	}
	if (check_p(str) != 1)
	{
		if (check_p(str) == 0)
			printf("Error\nMap doesn't contain a starting position\n");
		else
			printf("Error\nMap contains more than one starting position\n");
		return (0);
	}
}