/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:16:24 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/04 18:42:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	ft_argsize(t_args *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

char	**get_cmd(t_cmd *cmd)
{
	int		i;
	char	**str;
	t_args	*args;

	args = cmd->args_node;
	i = ft_argsize(args) + 1;
	str = malloc(sizeof(char *) * (i + 1));
	i = 0;
	str[i] = ft_strdup(cmd->cmd);
	i++;
	while (args)
	{
		str[i] = ft_strdup(args->word);
		i++;
		args = args->next;
	}
	str[i] = NULL;
	return (str);
}

void	exec_builtins(t_cmd *cmd, t_pathAndEnv *pEnv, int flag)
{
	char	***env;

	env = &(pEnv->envp);
	if (ft_strncmp(cmd->cmd, "echo", 5) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd->cmd, "cd", 3) == 0)
		ft_cd(cmd->args_node, env, &pEnv);
	else if (ft_strncmp(cmd->cmd, "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(cmd->cmd, "env", 4) == 0)
		ft_env(*env);
	else if (ft_strncmp(cmd->cmd, "exit", 5) == 0)
		ft_exit(cmd, flag);
	else if (ft_strncmp(cmd->cmd, "export", 7) == 0)
		ft_export(&pEnv, cmd->args_node);
	else if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
		ft_unset(cmd->args_node, env);
}

void	ft_env_ro(t_pathAndEnv **lst)
{
	int	i;

	i = 0;
	while ((*lst)->envp[i])
	{
		free((*lst)->envp[i]);
		i++;
	}
	free((*lst)->envp);
}

void	exec_cmd(t_cmd *cmd, t_pathAndEnv **pEnv)
{
	t_data	*data;
	int		i;

	data = init_execdata(cmd);
	init_pipes(&data);
	i = check_execpath(cmd, &data, *pEnv);
	if (i == 126 || i == 127)
		return ;
	if (!cmd->next && cmd->isbuiltin == 1)
	{
		exec_simplebuiltin(cmd, pEnv, data);
		return ;
	}
	i = 0;
	while (i < data->count)
	{
		if (cmd->wrong_cmd == false)
			exec_pipe(cmd, data, pEnv, i);
		cmd = cmd->next;
		i++;
	}
	cleanup_exec(data);
}
