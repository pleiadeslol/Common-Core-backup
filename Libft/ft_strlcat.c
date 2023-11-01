/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:28:34 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/01 20:34:40 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	j = d_len;
	if (n == 0 || n <= d_len)
		return (s_len + n);
	while (src[i] && i < n - d_len - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (d_len + s_len);
}
