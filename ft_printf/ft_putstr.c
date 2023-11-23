/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:32:47 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 20:16:33 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *ptr)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", ptr);
	while (str[i])
	{
		ft_putchar(str[i], ptr);
		i++;
	}
}
