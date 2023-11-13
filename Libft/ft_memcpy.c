/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:23:14 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/13 17:53:54 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	i = 0;
	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
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

int	main(void)
{
	char src[] = "segfaulter tu dois";
	size_t n = 17;
	printf("%s\n", (char *)ft_memcpy(((void *)0), src, n));
	printf("%s\n", (char *)memcpy(((void *)0), src, n));
	return (0);
}**/