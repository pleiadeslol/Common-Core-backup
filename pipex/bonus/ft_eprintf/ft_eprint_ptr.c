/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eprint_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:38:34 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/14 03:16:26 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eprintf.h"

void	ft_print_ptr(unsigned long p, int *ptr)
{
	if (p == 0)
		ft_putstr("(nil)", ptr);
	else
	{
		ft_putstr("0x", ptr);
		ft_puthex(p, 'x', ptr);
	}
}
