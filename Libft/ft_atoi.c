/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:22:24 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/14 20:32:54 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_sign(const char *str, int *i, int *j, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[(*i)++] == '-')
		{
			*sign = -1;
		}
		else
		{
			*sign = 1;
		}
		(*j)++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;
	int	res;

	i = 0;
	j = 0;
	sign = 1;
	res = 0;
	handle_sign(str, &i, &j, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (j > 1)
		return (0);
	else
		return (res * sign);
}
