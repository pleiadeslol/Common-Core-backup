/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:34:33 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/14 05:31:13 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	micro_lexer(t_node *node, char *dup, int len)
{
	if (ft_strncmp(node->word, "|", len) == 0)
		node->type = p;
	else if (ft_strncmp(node->word, ">", len) == 0)
		node->type = great;
	else if (ft_strncmp(node->word, "<", len) == 0)
		node->type = less;
	else if (ft_strncmp(node->word, ">>", len) == 0)
		node->type = Ggreat;
	else if (ft_strncmp(node->word, "<<", len) == 0)
		node->type = Lless;
	else if (!(node->prev) || (node->prev && node->prev->type == p)
		|| ft_condition1(node) || ft_condition2(node, dup))
		node->type = CMD;
	else if (node->word[0] == '-' || dup[0] == '-')
		node->type = opt;
	else if (node->prev && (node->prev->type == less))
		node->type = infile;
	else if (ft_condition3(node))
		node->type = outfile;
	else if (node->prev && node->prev->type == Lless)
		node->type = stop;
	else if (ft_condition4(node))
		node->type = arg;
	else
		node->type = file;
}

t_node	*lexer_mini(char **s)
{
	t_node	*node;
	t_node	*first;
	int		len;
	char	*dup;

	first = initialize_node(s);
	node = first;
	replace_pipe(&node);
	while (node)
	{
		ft_start_while(&node, &len, &dup);
		micro_lexer(node, dup, len);
		if (is_builtin(node->word))
			node->type = builtin;
		node = node->next;
		free(dup);
	}
	return (first);
}
