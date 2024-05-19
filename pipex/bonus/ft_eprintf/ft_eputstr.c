/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:32:47 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/14 03:16:39 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eprintf.h"

void	ft_putstr(char *str, int *ptr)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", ptr);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], ptr);
		i++;
	}
}
