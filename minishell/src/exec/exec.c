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

char	**get_cmd(t_cmd *cmd)
{
	char	**str;
	char	*c;
	char	*tmp;

	c = ft_strjoin(cmd->cmd, " ");
	if (cmd->args)
	{
		tmp = c;
		c = ft_strjoin(c, cmd->args);
		free(tmp);
	}
	str = ft_split(c, ' ');
	free(c);
	return (str);
}

void	exec_builtins(t_cmd *cmd, t_pathAndEnv *pEnv)
{
	char	***env;

	env = &(pEnv->envp);
	if (ft_strncmp(cmd->cmd, "echo", 5) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd->cmd, "cd", 3) == 0)
		ft_cd(cmd, env, &pEnv);
	else if (ft_strncmp(cmd->cmd, "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(cmd->cmd, "env", 4) == 0)
		ft_env(*env);
	else if (ft_strncmp(cmd->cmd, "exit", 5) == 0)
		ft_exit(cmd);
	else if (ft_strncmp(cmd->cmd, "export", 7) == 0)
		ft_export(&pEnv, cmd->args);
	else if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
		ft_unset(env, cmd->args);
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

void	set_status(int status_code)
{
	free(g_global->status);
	g_global->status = ft_itoa(status_code);
}

void	exec_cmd(t_cmd *cmd, t_pathAndEnv **pEnv)
{
	t_data	*data;
	int		i;

	data = init_execdata(cmd);
	init_pipes(&data);
	if (cmd->cmd && ft_strcmp(cmd->cmd, "") != 0)
	{
		i = check_execpath(cmd, &data, *pEnv);
		if (i == 126 || i == 127)
			return ;
	}
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
