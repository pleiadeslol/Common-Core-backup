/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper18.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:32:56 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/16 01:34:21 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_expand_var_tool1(char **env, char *tab, char **dup)
{
	int		j;
	size_t	len;

	j = 0;
	while (env[j])
	{
		len = len_env_var(env[j]);
		if (len == ft_strlen(tab)
			&& ft_strncmp(tab, env[j], len) == 0)
		{
			if (*dup)
				free(*dup);
			*dup = ft_strdup(env[j] + len + 1);
			break ;
		}
		else
		{
			if (*dup)
				free(*dup);
			*dup = ft_strdup("");
		}
		j++;
	}
}

void	ft_expand_var_tool2(char **tab, char **rslt, char **s)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		*rslt = ft_strjoin_2(*rslt, tab[i]);
		i++;
	}
	free(*s);
	*s = ft_strdup(*rslt);
	free(*rslt);
}

void	expand_var(char **s, char **env)
{
	int		i;
	char	**tab;
	char	*dup;
	char	*rslt;

	i = 0;
	rslt = ft_strdup("");
	dup = NULL;
	if (!(*s))
		return ;
	tab = ft_split(*s, '$');
	while (tab[i])
	{
		if (ft_strncmp(tab[i], "?", 1) == 0)
			dup = ft_replace_char(tab[i]);
		else
			ft_expand_var_tool1(env, tab[i], &dup);
		free(tab[i]);
		tab[i] = ft_strdup(dup);
		free(dup);
		i++;
	}
	(ft_expand_var_tool2(tab, &rslt, s), free_tab(tab));
}

t_cmd	*get_structure1(t_node *node)
{
	t_cmd	*first;
	t_args	*args_node;
	char	*c;
	t_redir	*red0;
	int		b;

	first = NULL;
	while (node)
	{
		ft_get_struct_helper0_1(&red0, &c, &args_node, &b);
		while (node && node->type != p)
		{
			if (node->type == CMD || node->type == builtin)
				ft_get_struct_helper1(&c, node, &b);
			else
				ft_get_struct_helper3_1(node, &red0, &args_node);
			node = node->next;
		}
		if (node && node->type == p)
			node = node->next;
		ft_cmdadd_back(&first, ft_get_struct_helper4_1(&c, args_node, red0, b));
	}
	return (first);
}

void	ft_heredoc_no_quotes(char *s, char **rslt)
{
	int		i;
	char	**dup;
	char	*tmp;

	dup = ft_split(s, '\'');
	tmp = ft_strdup("");
	i = 0;
	while (dup[i])
	{
		tmp = ft_strjoin_2(tmp, dup[i]);
		free(dup[i]);
		i++;
	}
	free(dup);
	dup = ft_split(tmp, '\"');
	free(tmp);
	i = 0;
	while (dup[i])
	{
		*rslt = ft_strjoin_2(*rslt, dup[i]);
		free(dup[i]);
		i++;
	}
	free(dup);
}
