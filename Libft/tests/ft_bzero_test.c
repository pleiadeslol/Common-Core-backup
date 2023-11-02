/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:03:41 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/02 14:08:21 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main()
{
	char	buf[10];

	ft_memset(buf, 'a', 10);
	printf("%s\n", buf);
	ft_bzero(buf, 2);
	printf("%s\n", buf);
	ft_bzero(buf, 10);
	printf("%s\n", buf);
	return (0);
}
