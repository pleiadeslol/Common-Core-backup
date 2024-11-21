/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:18:29 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/11 08:43:05 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	check_home(char *home)
{
	if (!home)
	{
		printf("minishell: cd: HOME not set\n");
		set_status(1);
		return ;
	}
}

void	cd_home(t_cmd *cmd, char *home)
{
	char	*tmp;

	check_home(home);
	tmp = ft_strtrim(cmd->args, "~");
	cmd->args = ft_strjoin(home, tmp);
	free(tmp);
	chdir(home);
}

void	cd_oldpwd(char ***env)
{
	char	*tmp;

	tmp = find_env((*env), "OLDPWD=");
	if (!tmp)
	{
		printf("minishell: cd: OLDPWD not set\n");
		set_status(1);
		return ;
	}
	chdir(tmp);
	printf("%s\n", tmp);
}

void	cd_path(t_cmd *cmd)
{
	if (chdir(cmd->args) == -1)
	{
		printf("minishell: cd: %s: %s\n", cmd->args, strerror(errno));
		set_status(1);
		return ;
	}
}

void	ft_cd(t_cmd *cmd, char ***env, t_pathAndEnv **pEnv)
{
	char	*home;
	char	*pwd;
	char	*old_pwd;
	char	s[100];

	home = find_env((*env), "HOME=");
	old_pwd = getcwd(s, 100);
	if (!cmd->args)
		(check_home(home), chdir(home));
	else if (ft_strchr(cmd->args, '~'))
		cd_home(cmd, home);
	else if (ft_strchr(cmd->args, '-'))
		cd_oldpwd(env);
	else
		cd_path(cmd);
	old_pwd = ft_strjoin("OLDPWD=", old_pwd);
	pwd = ft_strjoin("PWD=", getcwd(s, 100));
	ft_export(pEnv, old_pwd);
	ft_export(pEnv, pwd);
	free(old_pwd);
	free(pwd);
	set_status(0);
}
