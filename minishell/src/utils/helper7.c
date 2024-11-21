/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:23:21 by nalabdal          #+#    #+#             */
/*   Updated: 2024/09/11 19:07:01 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	parse(t_node *node)
{
	while (node)
	{
		if (node->next && node->next->type == p
			&& (node->type == great || node->type == Ggreat
				|| node->type == less || node->type == Lless))
		{
			printf("minishell: parse error near `|'\n");
			return (-1);
		}
		if ((node->type == great || node->type == Ggreat
				|| node->type == less || node->type == Lless) && !node->next)
		{
			printf("minishell: parse error near \\n\n");
			return (-1);
		}
		node = node->next;
	}
	return (0);
}

void	replace_pipe(t_node **node)
{
	t_node	*tmp;

	tmp = *node;
	while (*node)
	{
		if (ft_strncmp((*node)->word, ">|", 3) == 0)
		{
			free((*node)->word);
			(*node)->word = ft_strdup(">");
		}
		else if (ft_strncmp((*node)->word, ">>|", 4) == 0)
		{
			free((*node)->word);
			(*node)->word = ft_strdup(">>");
		}
		*node = (*node)->next;
	}
	*node = tmp;
}

char	*ft_strchr(char *s, int c)
{
	char	u;
	size_t	i;

	u = (char) c;
	i = 0;
	if (u == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == u)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int	var_lenth(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
