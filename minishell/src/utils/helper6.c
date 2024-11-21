/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:09:42 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/14 02:46:51 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_lstdelone(t_node *node)
{
	if (!node)
		return ;
	free(node->word);
	free(node);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	free_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	find_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] == '\'')
		{
			i += 1;
			ft_skip_quotes(s, &i, '\'');
			if (!s[i])
				break ;
		}
		if (s[i] && s[i] == '\"')
		{
			i += 1;
			ft_skip_quotes(s, &i, '\"');
			if (!s[i])
				break ;
		}
		if (s[i] && (s[i] == '|' || s[i] == '>' || s[i] == '<'))
			return (1);
		i++;
	}
	return (0);
}

int	empty_string(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == '\'' || s[i] == '\"' || s[i] == ' '))
		i++;
	if (s[i])
		return (0);
	return (1);
}
