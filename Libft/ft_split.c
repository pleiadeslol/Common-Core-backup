/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:44:31 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/13 14:49:20 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words_str(const char *s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*fill_words(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str_f;

	i = 0;
	if (!s)
		return (NULL);
	str_f = (char **)malloc(sizeof(char *) * (count_words_str(s, c) + 1));
	if (str_f == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		str_f[i] = fill_words(s, c);
		if (!str_f[i])
		{
			while(i--)
				free(str_f[i]);
			free(str_f);
			return (NULL);
		}
		s += ft_strlen(str_f[i++]);
	}
	str_f[i] = 0;
	return (str_f);
}

/**#include <stdio.h>

int main()
{
	char *str = "    g ";
	char c = ' ';
	char **str_f = ft_split(str, c);
	int i = 0;
	while (str_f[i])
	{
		printf("%s\n", str_f[i]);
		i++;	
	}
	return (0);
}**/