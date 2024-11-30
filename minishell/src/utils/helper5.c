/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:13:32 by nalabdal          #+#    #+#             */
/*   Updated: 2024/09/06 13:18:08 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
	s = (void *)t;
}

int	single_quote_cmd(char *s)
{
	char	*trim;

	if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		trim = ft_strtrim(s, "\'");
		if (find_space(trim) == 1)
			return (0);
		return (1);
	}
	return (0);
}

void	fill_the_blanks(char **s, char c)
{
	int	i;

	i = 0;
	while (((*s)[i] && (*s)[i] != c))
		i++;
	if (((*s)[i] && (*s)[i] == c))
		i++;
	while (((*s)[i] && (*s)[i] != c))
	{
		if ((*s)[i] == 32 || ((*s)[i] >= 9 && (*s)[i] <= 13))
			(*s)[i] *= (-1);
		i++;
	}
}

void	reverse_fill_the_blanks(char **s, char c)
{
	int	i;

	i = 0;
	while (((*s)[i] && (*s)[i] != c))
		i++;
	if (((*s)[i] && (*s)[i] == c))
		i++;
	while (((*s)[i] && (*s)[i] != c))
	{
		if ((*s)[i] == -32 || ((*s)[i] >= -13 && (*s)[i] <= -9))
			(*s)[i] *= (-1);
		i++;
	}
}

char	**rev_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		reverse_fill_the_blanks(&s[i], '\"');
		reverse_fill_the_blanks(&s[i], '\'');
		i++;
	}
	return (s);
}
