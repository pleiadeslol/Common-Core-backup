/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:21:23 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 20:16:16 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *ptr)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", ptr);
	else if (n < 0)
	{
		ft_putchar('-', ptr);
		ft_putnbr(-n, ptr);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, ptr);
		ft_putchar(n % 10 + '0', ptr);
	}
	else
		ft_putchar(n + '0', ptr);
}
