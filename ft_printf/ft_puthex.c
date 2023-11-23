/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:25:57 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 14:13:23 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n)
{
	char	*str;
	unsigned int		nbr;
	int		len;
	int		i;
	int		str_len;
	char	HEX[] = "0123456789abcdef";

	nbr = n;
	len = 0;
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return ;
	if (!n)
		ft_putchar('0');
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	while (i < len)
	{
        str[len - 1 - i] = HEX[n % 16];
        n /= 16;
		i++;
    }
	str[len] = '\0';
	ft_putstr(str);
	free(str);
}
