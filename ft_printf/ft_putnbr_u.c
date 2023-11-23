/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:24 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 12:28:27 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n)
{
	int				div;
	unsigned int	num;

	div = 1;
	num = n;
	while (num / div > 9)
		div *= 10;
	while (div != 0)
	{
		ft_putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
}
