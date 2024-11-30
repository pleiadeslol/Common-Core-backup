/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper14.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 05:31:36 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/14 05:35:29 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_condition1(t_node *node)
{
	if (node->next && (node->next->type == great
			|| node->next->type == Ggreat
			|| node->next->type == less
			|| node->next->type == Lless))
		return (1);
	return (0);
}

int	ft_condition2(t_node *node, char *dup)
{
	if (node->prev && node->prev->prev
		&& (node->prev->prev->type == great
			|| node->prev->prev->type == Ggreat
			|| node->prev->prev->type == less
			|| node->prev->prev->type == Lless)
		&& !node->prev->prev->prev
		&& node->word[0] != '-' && dup[0] != '-')
		return (1);
	return (0);
}

int	ft_condition3(t_node *node)
{
	if (node->prev && (node->prev->type == great
			|| node->prev->type == Ggreat))
		return (1);
	return (0);
}

int	ft_condition4(t_node *node)
{
	if (node->prev && (node->prev->type == CMD
			|| node->prev->type == builtin
			|| node->prev->type == opt))
		return (1);
	return (0);
}

t_node	*initialize_node(char **s)
{
	t_node	*first;

	first = NULL;
	check_quotes_line_before(&first, s);
	check_pipe_char_line(&first, s);
	return (first);
}
