/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper24.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:22:08 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/25 23:22:09 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_argsdelone(t_args *lst)
{
	if (!lst)
		return ;
	free(lst->word);
	free(lst);
}

void	ft_clear_args(t_args **lst)
{
	t_args	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_argsdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

t_args	*ft_argnew(char *word, enum e_symbol type)
{
	t_args	*node;

	node = (t_args *)ft_calloc(1, sizeof(t_args));
	if (!node)
		return (0);
	node->word = ft_strdup(word);
	node->type = type;
	node->empty_arg = 0;
	node->next = 0;
	return (node);
}

void	ft_argadd_back(t_args **lst, t_args *new)
{
	t_args	*curr;

	if (!new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	ft_helper_args(t_cmd **cmds, char *s, char *rslt)
{
	free((*cmds)->args_node->word);
	if (find_emptycmd(s) != 1)
		(*cmds)->args_node->word = ft_strdup(rslt);
	else if (find_emptycmd(s) == 1)
	{
		(*cmds)->args_node->word = ft_strtrim(s, "\"\'");
		(*cmds)->args_node->empty_arg = 1;
	}
}
