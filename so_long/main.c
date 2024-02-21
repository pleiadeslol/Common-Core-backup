/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:29 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/21 01:56:20 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include "headers/get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int i;
	int	count;
	char	*line;
	t_point size;
	t_point cur;

	fd = open(av[1], O_RDONLY);
	i = 1;
	count = count_line(fd);
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
	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	char **str = malloc(sizeof(char **) * (count + 1));
	if (!str)
	{
		printf("Error\nError allocating!\n");
		return (0);
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (ft_strlen(ft_strtrim(line, "\n")) == 0)
	{
		line = get_next_line(fd);
	}
	str[0] = ft_strtrim(ft_strdup(line), "\n");
	while ((str[i] = get_next_line(fd)) && i < count)
	{
		str[i] = ft_strtrim(str[i], "\n");
		i++;
	}
	str[i] = NULL;
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
	i = 0;
	int j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P'){
				cur.x = j;
				cur.y = i;
			}
			j++;
		}
		i++;
	}
	size.x = j;
	size.y = i;
	int req_c = check_c(str);
	char **tab_c = copy_str(av[1], count);
	char **tab_e = copy_str(av[1], count); //fixed
	flood_fill(tab_c, tab_e, size, cur, req_c);
}
