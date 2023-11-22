/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoidptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:38:34 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/22 17:27:33 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(void *p)
{
	unsigned char	tmp;
	char			*str;

	if (p == 0)
		ft_putstr("(nil)");
	else if (p <= 15)
	{
		ft_putstr("0x");
		ft_putnbr_base((int)p, HEX);
	}
}

#include <stdio.h>

int	main(void)
{
	void *p;
	for (p = 0; p < 20; p++)
		ft_print_ptr(p);
	return (0);
}