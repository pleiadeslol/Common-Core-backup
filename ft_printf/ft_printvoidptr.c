/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoidptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:38:34 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/22 17:24:13 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_ptr(void *p)
{
	unsigned char	tmp;
	char			*str;

	if (p == 0)
		ft_putstr("(nil)");
	else if (p <= 15)
	{
		ft_putstr("0x");
		ft_print_hex((int)p);
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	void *p;
// 	for (p = 0; p < 20; p++)
// 		printf("%p\n", p);
// 	return (0);
// }