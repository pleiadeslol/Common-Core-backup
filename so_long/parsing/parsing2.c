/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:11:30 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/19 18:14:10 by rzarhoun         ###   ########.fr       */
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

	len = ft_strlen(str[0]);
	s = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		s[i] = '1';
		i++;
	}
	i = 0;
	while (str[i])
		i++;
	if (ft_strcmp(str[0], s) != 0 || ft_strcmp(str[i - 1], s) != 0)
		return (0);
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
int	check_char(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'E' 
				&& str[i][j] != 'C' && str[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill()
{
	
}
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
