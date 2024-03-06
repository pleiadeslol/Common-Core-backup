/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:25:57 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 21:03:42 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, char x, int *ptr)
{
	char	*str;

	if (x == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar(str[n], ptr);
	}
	else
	{
		ft_puthex(n / 16, x, ptr);
		ft_puthex(n % 16, x, ptr);
	}
}
