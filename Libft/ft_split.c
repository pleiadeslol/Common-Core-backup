/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:44:31 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/06 23:03:57 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words_str(const char *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	count;
	char	**str_f;

	i = 0;
	if (s == NULL)
		return (NULL);
	count = count_words_str(s, c);
	str_f = (char **)malloc(sizeof(char) * (count + 1));
	if (str_f == NULL)
		return (NULL);
}
