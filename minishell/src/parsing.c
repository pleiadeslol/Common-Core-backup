/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:42:17 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/18 08:37:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_global	*g_global;

void	main_helper2(t_pathAndEnv *p_env, t_node *node)
{
	t_cmd	*cmds;

	cmds = get_structure(node);
	handle_quotes_vars(&cmds, p_env->envp);
	expand_args(&cmds, p_env->envp);
	expand_files(&cmds, p_env->envp);
	if (node)
		ft_lstclear(&node);
	exec_cmd(cmds, &p_env);
	ft_cmdclear(&cmds);
}

int	main(int argc, char **argv, char **env)
{
	t_pathAndEnv	*p_env;
	char			*line;
	int				p;
	t_node			*node;

	if (ft_check_args_main(&argc, &argv, &p_env, env) != 0)
		return (1);
	node = NULL;
	line = ft_strdup("");
	handle_signals();
	while (line)
	{
		free(line);
		line = readline("minishell$ ");
		handle_exit(&line, &p_env);
		if (line)
			p = parse_line(line);
		add_history (line);
		if (line && *line && p == 0)
			main_helper3(&node, p_env, &line);
	}
	if (line)
		free(line);
	(ft_clear_path_env(&p_env), free(g_global->status));
	return (0);
}
