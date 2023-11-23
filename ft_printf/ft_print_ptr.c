/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:38:34 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 14:38:43 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long p)
{
	unsigned char	tmp;
	char			*str;

	if (p == 0)
		ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		ft_puthex(p);
	}
}
