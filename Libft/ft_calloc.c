/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:45:51 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/13 18:23:10 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	s;
	void	*p;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	s = nmemb * size;
	p = malloc(s);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, s);
	return (p);
}

/**#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *p = ft_calloc(10, 0);
	void *p1 = calloc(10, 0);
	printf("%p\n", p);
	printf("%p\n", p1);
	return (0);
}**/