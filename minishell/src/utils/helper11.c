/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:51:36 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/14 05:29:00 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_clear_redir(t_redir **lst)
{
	t_redir	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_redirdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_cmddelone1(t_cmd *lst)
{
	if (!lst)
		return ;
	free(lst->cmd);
	ft_clear_redir(&(lst->redir));
	ft_clear_args(&(lst->args_node));
	free(lst);
}

void	ft_cmdclear1(t_cmd **lst)
{
	t_cmd	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_cmddelone1(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_skip_quotes(char *s, int *i, char c)
{
	while (s[*i] && s[*i] != c)
		(*i)++;
	if (s[*i] && s[*i] == c)
		*i += 1;
}

void	ft_start_while(t_node **node, int *len, char **dup)
{
	(*node)->var = has_dollar((*node)->word);
	(*node)->sq = has_sq((*node)->word);
	(*node)->dq = has_dq((*node)->word);
	*len = ft_strlen((*node)->word);
	*dup = ft_strtrim((*node)->word, "\"\'");
}
