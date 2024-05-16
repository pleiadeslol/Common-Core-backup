/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eputnbr_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:04:24 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/14 03:16:35 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eprintf.h"

void	ft_putnbr_u(unsigned int n, int *ptr)
{
	int				div;
	unsigned int	num;

	div = 1;
	num = n;
	while (num / div > 9)
		div *= 10;
	while (div != 0)
	{
		ft_putchar('0' + num / div, ptr);
		num %= div;
		div /= 10;
	}
}
