/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:26:04 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/14 21:04:12 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*t;
	size_t	i;

	t = (char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (s);
}

/**#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "hello";
	ft_memset(str, 0, 2);
	for (size_t i = 0; i < sizeof(str); i++){
		printf("str[%zu] : %c\n",i, str[i]);}
	return (0);
}**/
