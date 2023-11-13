/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:47:23 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/13 16:33:13 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char dest[] = "jjhang";
	char src[] = "abcdef";
	size_t n = 4;
	printf("%s\n", (char *)ft_memmove(dest, src, n));
	printf("%s\n", (char *)ft_memmove(dest, src, n));
	return 0;
}