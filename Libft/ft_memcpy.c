/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:23:14 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/13 16:32:48 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	i = 0;
	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (dest == NULL)
		return (NULL);
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

/**#include <stdio.h>
#include <string.h>

int main()
{
	char dest[] = "jjhang";
	char src[] = "abcdef";
	size_t n = 4;
	printf("%s\n", (char *)ft_memcpy(dest, src, n));
	printf("%s\n", (char *)memcpy(dest, src, n));
	return 0;
}**/