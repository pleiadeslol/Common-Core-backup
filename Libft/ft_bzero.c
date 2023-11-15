/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:23:33 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/14 21:04:56 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/**#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = " ";
	ft_bzero(s, 1);
	printf("ft : %s, address : %p\n", s, (void *)s);
	return 0;
}**/