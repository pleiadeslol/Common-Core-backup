/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:07:15 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/13 19:23:36 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_fill_rest(char *s2, char *join, size_t i)
{
	size_t	j;

	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
}

static void	strjoin_check(char **s1, int *flag)
{
	if (!*s1)
	{
		*s1 = ft_strdup("");
		*flag = 1;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	int		flag;
	char	*join;

	flag = 0;
	strjoin_check(&s1, &flag);
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	ft_fill_rest(s2, join, i);
	if (flag == 1)
		free(s1);
	return (join);
}

char	*body_loops(int i, int j, char *s, char *s_space)
{
	char	*copy;

	while (s[i])
	{
		while (s[i] && s[i] != '|' && s[i] != '>' && s[i] != '<')
			i++;
		copy = ft_substr(s, j, i - j);
		j = i;
		s_space = ft_strjoin_2(s_space, copy);
		free(copy);
		if (!s[i])
			break ;
		s_space = ft_strjoin_2(s_space, " ");
		while (s[i] && (s[i] == '|' || s[i] == '>' || s[i] == '<'))
			i++;
		copy = ft_substr(s, j, i - j);
		j = i;
		s_space = ft_strjoin_2(s_space, copy);
		free(copy);
		if (!s[i])
			break ;
		s_space = ft_strjoin_2(s_space, " ");
	}
	return (s_space);
}

char	*add_space(char *s)
{
	int		i;
	int		j;
	char	*s_space;

	j = 0;
	i = 0;
	s_space = ft_strdup("");
	return (body_loops(i, j, s, s_space));
}
