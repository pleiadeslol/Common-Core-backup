/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper21.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:19:42 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/18 08:19:43 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_trim_space(char **rslt)
{
	char	*dup;

	dup = ft_strtrim(*rslt, " \t\n\v\f\r");
	free(*rslt);
	*rslt = ft_strdup(dup);
	free(dup);
}

void	helper_replace_space(char *line, int *i, char **s)
{
	int		j;
	char	*dup;

	j = (*i);
	while (line[(*i)] && !(line[(*i)] == 32
			|| (line[(*i)] >= 9 && line[(*i)] <= 13)))
		(*i)++;
	dup = ft_substr(line, j, (*i) - j + 1);
	*s = ft_strjoin_2(*s, dup);
	free(dup);
	if (line[(*i)])
		*s = ft_strjoin_2(*s, " ");
}

void	replace_tab_space(char **line)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	while ((*line)[i])
	{
		while ((*line)[i] == 32 || ((*line)[i] >= 9 && (*line)[i] <= 13))
			i++;
		if ((*line)[i])
			helper_replace_space(*line, &i, &s);
		if (!(*line)[i])
			break ;
		i++;
	}
	free(*line);
	*line = ft_strdup(s);
	free(s);
}

void	expand_args1(t_cmd **cmds, char **env)
{
	t_cmd	*tmp;
	t_args	*tmp_args;
	char	*s;
	char	*rslt;

	tmp = *cmds;
	while (*cmds)
	{
		tmp_args = (*cmds)->args_node;
		while ((*cmds)->args_node)
		{
			s = ft_calloc(sizeof(char),
					ft_strlen((*cmds)->args_node->word) + 2);
			ft_strlcpy(s, (*cmds)->args_node->word,
				ft_strlen((*cmds)->args_node->word) + 1);
			rslt = ft_strdup("");
			ft_handle_quotes_helper2(s, &rslt, env);
			ft_helper_args(cmds, s, rslt);
			(free(s), free(rslt));
			(*cmds)->args_node = ((*cmds)->args_node)->next;
		}
		(*cmds)->args_node = tmp_args;
		*cmds = (*cmds)->next;
	}
	*cmds = tmp;
}

void	check_str(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '=' && str[i + 1] == ' ')
		{
			free(str);
			str = "";
			break ;
		}
		i++;
	}
}
