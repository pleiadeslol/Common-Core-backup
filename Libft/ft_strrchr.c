/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:44:18 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/11 23:17:23 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (!(char)c)
		return ((char *)&s[i]);
	return (0);
}

/**#include <stdio.h>
#include <string.h>

int main()
{
	char s[]= "tripouille";
	printf("%s\n", ft_strrchr(s, 't' + 256));
	printf("%s\n", strrchr(s, 't' + 256));
	return 0;
}**/