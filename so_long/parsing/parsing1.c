/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:22 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/02 20:12:59 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

// the map should be a .ber file
int	check_ber(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(ft_strchr(str, '.'), "ber", 4) == 0)
		return (1);
	else
		return (0);
}

// the map should be rectangular
int	check_len(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = ft_strlen(str[0]);
	while (str[i])
	{
		if (count != ft_strlen(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//the map must contain 1 e, 1 c, and 1 p
int	check_e(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'e')
			i++;
		return (1);
	}
	return (0);
}

int	check_c(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'c')
			i++;
		return (1);
	}
	return (0);
}

int	check_p(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'p')
			i++;
		return (1);
	}
	return (0);
}
