/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper20.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:19:26 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/21 06:27:37 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_hquote_helper1(int *i, char **rslt, char *s)
{
	char	*dup;
	int		j;

	j = *i;
	*i += 1;
	dup = ft_substr(s, j, (*i) - j);
	if (find1(dup, '$') > 0)
		(*rslt) = ft_strjoin_2((*rslt), "");
	free(dup);
}

void	ft_hquote_helper3(char *s, int *i, char **rslt, char **env)
{
	int		j;
	char	*dup;

	if (s[*i] == '$' && s[(*i) + 1]
		&& !ft_isalnum(s[(*i) + 1]) && s[(*i) + 1] != '$'
		&& s[(*i) + 1] != '?' && s[(*i) + 1] != '_')
		ft_hquote_helper1(i, rslt, s);
	j = (*i);
	while (s[(*i)] && s[(*i)] != '\'' && s[(*i)] != '\"')
		(*i)++;
	dup = ft_substr(s, j, (*i) - j);
	if (find(dup, '$') > 0)
		expand_2(&dup, env);
	(*rslt) = ft_strjoin_2((*rslt), dup);
	free(dup);
}

void	ft_hq_minihelper(int *i, char *s, char c, char **dup)
{
	int	j;

	(*i) += 1;
	j = (*i);
	while (s[(*i)] && s[(*i)] != c)
		(*i)++;
	*dup = ft_substr(s, j, (*i) - j);
}

void	ft_handle_quotes_helper2(char *s, char **rslt, char **env)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i])
	{
		ft_hquote_helper3(s, &i, rslt, env);
		if (s[i] && s[i] == '\"')
		{
			ft_hq_minihelper(&i, s, '\"', &dup);
			if (find(dup, '$') > 0)
				expand_2(&dup, env);
			*rslt = ft_strjoin_2(*rslt, dup);
			free(dup);
		}
		else if (s[i] && s[i] == '\'')
		{
			ft_hq_minihelper(&i, s, '\'', &dup);
			*rslt = ft_strjoin_2(*rslt, dup);
			free(dup);
		}
		i++;
	}
}

void	handle_quotes_vars(t_cmd **cmds, char **env)
{
	t_cmd	*tmp;
	char	*s;
	char	*rslt;

	tmp = *cmds;
	while (*cmds)
	{
		if ((*cmds)->cmd)
		{
			s = ft_calloc(sizeof(char), ft_strlen((*cmds)->cmd) + 2);
			ft_strlcpy(s, (*cmds)->cmd, ft_strlen((*cmds)->cmd) + 1);
			rslt = ft_strdup("");
			ft_handle_quotes_helper2(s, &rslt, env);
			ft_trim_space(&rslt);
			if (find_emptycmd(s) != 1)
			{
				free((*cmds)->cmd);
				(*cmds)->cmd = ft_strdup(rslt);
			}
			free(rslt);
			free(s);
		}
		*cmds = (*cmds)->next;
	}
	*cmds = tmp;
}
