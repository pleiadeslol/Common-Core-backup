/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:22:24 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/17 11:30:01 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**static void	handle_sign(const char *str, int *i, int *j, int *sign)
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
}**/

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807 / 10)
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}
