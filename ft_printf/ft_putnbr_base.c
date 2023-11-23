/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:21:23 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/22 23:46:24 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;
	int	b_len;

	i = 0;
	j = i + 1;
	b_len = ft_strlen(base);
	while (base[i])
	{
		if (base[i] == base[j])
			return ;
		if (b_len == 0 || b_len == 1)
			return ;
		if (base[i] == '-' || base[i] == '+')
			return ;
		i++;
	}
	if (nbr < b_len)
		ft_putchar(base[nbr % b_len]);
	else
	{
		ft_putnbr_base(nbr / b_len, base);
		ft_putnbr_base(nbr % b_len, base);
	}
}

int main()
{
	unsigned long p = 11;
	char HEX[] = "0123456789abcdef";
	ft_putnbr_base(p, HEX);
	return 0;
}
