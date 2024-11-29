/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper17.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:25 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/16 01:33:26 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_expand2_loop1(char **s, char **dup, char **rslt, int *i)
{
	int	j;

	j = *i;
	while ((*s)[(*i)] && (*s)[(*i)] != '$')
		(*i)++;
	(*dup) = ft_substr((*s), j, (*i) - j);
	(*rslt) = ft_strjoin_2((*rslt), (*dup));
	free(*dup);
}

void	ft_expand2_loop2(char **s, char **dup, char **env, int *i)
{
	int	j;

	j = *i;
	*i += 1;
	while ((*s)[(*i)] && (*s)[(*i)] != '$' && (*s)[(*i)] != ' '
			&& (*s)[(*i)] != '\'' && (*s)[(*i)] != '\"'
			&& (*s)[(*i)] != '/' && (*s)[(*i)] != '=')
		(*i)++;
	*dup = ft_substr((*s), j, (*i) - j);
	expand_var(dup, env);
}

void	ft_expand2_loop3(char **s, char **rslt, int *i)
{
	char	*c;

	if ((*s)[*i])
	{
		c = (char *)ft_calloc(sizeof(char), 2);
		c[0] = (*s)[*i];
		c[1] = '\0';
		*rslt = ft_strjoin_2(*rslt, c);
		free(c);
		(*i)++;
	}
}

void	expand_2(char **s, char **env)
{
	int		i;
	char	*dup;
	char	*rslt;

	i = 0;
	rslt = ft_strdup("");
	while ((*s)[i])
	{
		ft_expand2_loop1(s, &dup, &rslt, &i);
		if ((*s)[i] && (*s)[i] == '$' && (*s)[i + 1])
		{
			ft_expand2_loop2(s, &dup, env, &i);
			rslt = ft_strjoin_2(rslt, dup);
			free(dup);
		}
		else
			ft_expand2_loop3(s, &rslt, &i);
	}
	free(*s);
	(*s) = ft_strdup(rslt);
	free(rslt);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
