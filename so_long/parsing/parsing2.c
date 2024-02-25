/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:11:30 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/25 22:13:51 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../headers/so_long.h"
#include "../ft_printf/ft_printf.h"

// the map must be closed/surrounded bt walls
int	check_corners(char **str, int len)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][len - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **str, int count)
{
	int		i;
	int		len;

	len = ft_strlen(str[0]);
	i = 0;
	while (str[0][i])
	{
		if (str[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (str[count - 1][i])
	{
		if (str[count - 1][i] != '1')
			return (0);
		i++;
	}
	if (check_corners(str, len) == 0)
		return (0);
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

void	trim_line(char **str, int count, int fd, char *line)
{
	int	i;

	i = 1;
	line = ft_strtrim(get_next_line(fd), "\n");
	while (line && i < count)
	{
		str[i] = ft_strdup(line);
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");
		i++;
	}
	free(line);
	str[i] = NULL;
}

char	**copy_str(char *av, int count)
{
	char	**str;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	line = ft_strtrim(get_next_line(fd), "\n");
	str = malloc(sizeof(char **) * (count + 1));
	if (!str)
	{
		ft_printf("Error\nError allocating!\n");
		return (0);
	}
	while (ft_strlen(line) == 0)
	{
		free(line);
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	str[0] = ft_strdup(line);
	free (line);
	trim_line(str, count, fd, line);
	return (str);
}
