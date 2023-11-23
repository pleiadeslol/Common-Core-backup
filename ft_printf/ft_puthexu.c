/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:56 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 14:08:20 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexu(unsigned int n)
{
	char	*str;
	int		nbr;
	int		len;
	int		i;
	int		str_len;
	char	HEXU[] = "0123456789ABCDEF";

	nbr = n;
	len = 0;
	i = 0;
    if (!n)
        ft_putchar('0');
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	while (i < len)
	{
        str[len - 1 - i] = HEXU[n % 16];
        n /= 16;
		i++;
    }
	str[len] = '\0';
	ft_putstr(str);
}
