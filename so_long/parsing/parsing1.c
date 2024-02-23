/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:22 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/23 16:43:25 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/get_next_line.h"

// the map should be a .ber file
int	check_ber(char *str)
{
	if (ft_strchr(str, '.') == NULL)
		return (0);
	else if (ft_strncmp(ft_strchr(str, '.'), ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

// the map should be rectangular
int	check_len(char **str, int count)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str[0]);
	while (i < count)
	{
		if (len != ft_strlen(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//the map must contain 1 e, 1 c, and 1 p
int	check_e(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_c(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_p(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
