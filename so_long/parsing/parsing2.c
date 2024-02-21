/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:11:30 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/21 01:55:21 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/so_long.h"

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
	s[i] = '\0';
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

char **copy_str(char *av, int count)
{
	int i;
	char **str;
	char *line;
	int fd;

	i = 1;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	str = malloc(sizeof(char **) * (count + 1));
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
	return (str);
}
