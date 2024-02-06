/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:11:30 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/06 16:51:57 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

// the map must be closed/surrounded bt walls
int	check_walls(char **str)
{
	int		i;
	int		len;
	char	*s;

	len = ft_strlen(str[0]) - 1;
	s = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		s[i] = '1';
		i++;
	}
	s[i] = '\n';
	i = 0;
	while (str[i])
		i++;
	// first line and last line should be all walls
	if (ft_strcmp(str[0], s) != 0 || ft_strcmp(str[i - 1], s) != 0)
		return (0);
	// there should be walls in  corners of each line
	i = 0;
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

// the map can be composed of only the 5 characters


/**void map_parsing(int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((line = get_next_line(fd)))
	{
		while (line[i])
		{
			if (line[i] == '1')
				draw_wall();
			else if (line[i] == '0')
				draw_floor();
			else if (line[i] == 'P')
				draw_player();
			else if (line[i] == 'C')
				draw_collectible();
			else if (line[i] == 'E')
				draw_exit();
			else
				error();
			i++;
		}
		j++;
	}
}**/
