/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:38:34 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/22 23:42:43 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long p)
{
	unsigned char	tmp;
	char			*str;
	char	HEX[] = "0123456789abcdef";

	if (p == 0)
		ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		ft_putnbr_base(p, HEX);
	}
}

#include <stdio.h>

int	main(void)
{
	unsigned long p = 11;
	ft_print_ptr(p);
	return (0);
}