/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:57:19 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/24 22:02:28 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"

int	count_line(int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
			count++;
		free (line);
		line = get_next_line(fd);
	}
	free(line);
	return (count);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_point	find_cur(char **str)
{
	int		i;
	int		j;
	t_point	cur;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				cur.x = j;
				cur.y = i;
			}
			j++;
		}
		i++;
	}
	return (cur);
}

t_point	find_size(char **str)
{
	int		i;
	int		j;
	t_point	size;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		i++;
	}
	size.x = j;
	size.y = i;
	return (size);
}
