/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:53:39 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/14 03:16:42 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eprintf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != '\0' && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
	{
		return ((char *)&str[i]);
	}
	return (0);
}
