/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:13 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/05 18:19:19 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../get_next_line/get_next_line.h"

int	count_line(int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd, 0);
	count = 0;
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
			count++;
		line = get_next_line(fd, 0);
	}
	return (count);
}

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

static void	free_split(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
}

char	**ft_split(char *s, char c)
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
			free_split(str_f, i);
			return (NULL);
		}
		s += ft_strlen(str_f[i++]);
	}
	str_f[i] = NULL;
	return (str_f);
}
