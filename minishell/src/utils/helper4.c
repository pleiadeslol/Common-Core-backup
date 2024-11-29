/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:12:01 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/13 03:00:54 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	if (!src && !dst && !size)
		return (0);
	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

static int	ft_check(char c, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	if (!s1 || !*s1)
		return (NULL);
	if (!set || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_check(s1[i], set) == 1)
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (s1[j] && ft_check(s1[j], set) == 1)
		j--;
	if (!s1[i] || !s1[j])
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + i, j - i + 2);
	return (trim);
}

int	find_space(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (1);
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	double_quote_cmd(char *s)
{
	char	*trim;

	if (s[0] == '\"' && s[ft_strlen(s) - 1] == '\"')
	{
		trim = ft_strtrim(s, "\"");
		if (find_space(trim) == 1)
			return (0);
		return (1);
	}
	return (0);
}
