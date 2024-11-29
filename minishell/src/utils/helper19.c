/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper19.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:54 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/16 01:33:58 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_get_struct_helper1(char **c, t_node *node, int *b)
{
	free(*c);
	*c = ft_strdup(node->word);
	if (node->type == builtin)
		*b = 1;
	else
		*b = 0;
}

void	ft_get_struct_helper2(t_redir **red0, t_node *node)
{
	t_redir	*red;

	red = ft_rednew(node->type);
	node = node->next;
	if (node->type == stop && (node->sq > 0 || node->dq > 0))
		red->expansion = 0;
	else
		red->expansion = 1;
	if (node->type == stop)
		red->heredoc = node->word;
	else
		red->heredoc = NULL;
	if (node->type != stop)
		red->file = node->word;
	else
		red->file = NULL;
	ft_redadd_back(red0, red);
}

void	ft_get_struct_helper0_1(t_redir **red0, char **c, t_args **args, int *b)
{
	*red0 = NULL;
	*c = ft_strdup("");
	*args = NULL;
	*b = -1;
}

void	ft_get_struct_helper3_1(t_node *node, t_redir **red0, t_args **args)
{
	if (node->type == 2 || node->type == 3
		|| node->type == 4 || node->type == 5)
		ft_get_struct_helper2(red0, node);
	else if (node->type == opt || node->type == arg
		|| node->type == file)
		ft_get_struct_args(args, node);
}

t_cmd	*ft_get_struct_helper4_1(char **c, t_args *args, t_redir *red0, int b)
{
	t_cmd	*cmds;

	cmds = ft_cmdnew(*c);
	cmds->empty_arg = 0;
	free(*c);
	if (b == -1)
	{
		if (cmds->cmd)
			free(cmds->cmd);
		cmds->cmd = NULL;
	}
	else if (b)
		cmds->isbuiltin = 1;
	else
		cmds->isbuiltin = 0;
	if (args)
		cmds->args_node = args;
	else
		cmds->args_node = NULL;
	if (red0)
		cmds->redir = red0;
	else
		cmds->redir = ft_rednew(0);
	return (cmds);
}
