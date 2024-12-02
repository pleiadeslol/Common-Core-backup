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

static int	check_cd(t_args *args, char *home, char *old_pwd,
		t_pathAndEnv **pEnv)
{
	char	s[100];

	if (!args)
	{
		if (!home)
		{
			printf("minishell: cd: HOME not set\n");
			return (set_status(1), 1);
		}
		chdir(home);
		update_env(pEnv, "OLDPWD", old_pwd);
		update_env(pEnv, "PWD", getcwd(s, 100));
		return (1);
	}
	if (getcwd(s, 100) == NULL)
	{
		printf("minishell: cd: Unable to determine current directory\n");
		return (set_status(1), 1);
	}
	if (args && args->next)
	{
		printf("minishell: cd: too many arguments\n");
		return (set_status(1), 1);
	}
	return (0);
}

int	cd_home(char *args, char *home)
{
	char	*tmp;

	if (!home)
	{
		printf("minishell: cd: HOME not set\n");
		set_status(1);
		return (1);
	}
	tmp = ft_strtrim(args, "~");
	args = ft_strjoin(home, tmp);
	free(tmp);
	chdir(home);
	return (0);
}

int	cd_oldpwd(char ***env)
{
	char	*tmp;

	tmp = find_env((*env), "OLDPWD=");
	if (!tmp)
	{
		printf("minishell: cd: OLDPWD not set\n");
		set_status(1);
		return (1);
	}
	chdir(tmp);
	printf("%s\n", tmp);
	return (0);
}

int	cd_path(char *args)
{
	if (chdir(args) == -1)
	{
		printf("minishell: cd: %s: %s\n", args, strerror(errno));
		set_status(1);
		return (1);
	}
	return (0);
}

void	ft_cd(t_args *args, char ***env, t_pathAndEnv **pEnv)
{
	char	*home;
	char	*old_pwd;
	char	s[100];
	int		status;

	status = 0;
	home = find_env((*env), "HOME=");
	old_pwd = getcwd(s, 100);
	if (check_cd(args, home, old_pwd, pEnv))
		return ;
	else if (ft_strchr(args->word, '~'))
		status = cd_home(args->word, home);
	else if (ft_strchr(args->word, '-'))
		status = cd_oldpwd(env);
	else
		status = cd_path(args->word);
	if (status)
		return ;
	update_env(pEnv, "OLDPWD", old_pwd);
	update_env(pEnv, "PWD", getcwd(s, 100));
	set_status(0);
}
