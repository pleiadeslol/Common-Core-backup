/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:56 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 14:50:04 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hexu_digits(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*convert_int_hexu(unsigned int n, int len)
{
	int				i;
	char			*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	len = count_hexu_digits(n);
	while (i < len)
	{
		str[len - 1 - i] = HEXU[n % 16];
		n /= 16;
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	ft_puthexu(unsigned int n)
{
	char	*str;
	int		len;

	len = count_hexu_digits(n);
	str = convert_int_hexu(n, len);
	if (!n)
		ft_putchar('0');
	if (str)
	{
		ft_putstr(str);
		free(str);
	}
}
