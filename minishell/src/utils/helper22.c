/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper22.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:19:50 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/18 08:19:52 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_expand_file_file(t_cmd **cmds, char **env)
{
	char	*s;
	char	*rslt;

	s = ft_calloc(sizeof(char),
			ft_strlen((*cmds)->redir->file) + 2);
	ft_strlcpy(s, (*cmds)->redir->file,
		ft_strlen((*cmds)->redir->file) + 1);
	rslt = ft_strdup("");
	ft_handle_quotes_helper2(s, &rslt, env);
	(*cmds)->redir->file = ft_strdup(rslt);
	free(rslt);
	free(s);
}

void	ft_expand_file_heredoc(t_cmd **cmds)
{
	char	*s;
	char	*rslt;

	s = ft_calloc(sizeof(char),
			ft_strlen((*cmds)->redir->heredoc) + 2);
	ft_strlcpy(s, (*cmds)->redir->heredoc,
		ft_strlen((*cmds)->redir->heredoc) + 1);
	rslt = ft_strdup("");
	ft_heredoc_no_quotes(s, &rslt);
	(*cmds)->redir->heredoc = ft_strdup(rslt);
	free(rslt);
	free(s);
}

void	expand_files(t_cmd **cmds, char **env)
{
	t_cmd	*tmp;
	t_redir	*tmp_red;

	tmp = *cmds;
	while (*cmds)
	{
		tmp_red = (*cmds)->redir;
		while ((*cmds)->redir)
		{
			if ((*cmds)->redir->file)
				ft_expand_file_file(cmds, env);
			else if ((*cmds)->redir->heredoc)
				ft_expand_file_heredoc(cmds);
			(*cmds)->redir = ((*cmds)->redir)->next;
		}
		(*cmds)->redir = tmp_red;
		*cmds = (*cmds)->next;
	}
	*cmds = tmp;
}

int	ft_space_string(char *s)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i])
		return (0);
	else
		return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*t;

	if (nmemb == 0 || size == 0)
		return (NULL);
	t = (void *)malloc(nmemb * size);
	if (!t)
		return (NULL);
	ft_bzero(t, nmemb * size);
	return (t);
}
