/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:28:00 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/01 20:28:04 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;

	a = 48;
	b = 77;
	c = 61;
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha(b));
	printf("%d\n", ft_isalpha(c));
	return (0);
}
