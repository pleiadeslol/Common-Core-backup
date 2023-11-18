/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:45:51 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/18 18:16:38 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	s;
	void	*p;
	
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
