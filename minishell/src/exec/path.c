/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:44:53 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/14 01:33:57 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	handle_path1(char *cmd, char **p)
{
	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == -1)
	{
		printf("%s: permission denied\n", cmd);
		return (126);
	}
	if (access(cmd, X_OK) == -1 && (cmd[0] != '.' || ft_strchr(cmd, '/')))
	{
		printf("%s: No such file or directory\n", cmd);
		return (127);
	}
	*p = ft_strdup(cmd);
	return (0);
}

static int	handle_path_err(char **p, char *cmd)
{
	if (access(*p, F_OK) == 0 && access(*p, X_OK) == -1)
	{
		printf("%s: permission denied\n", cmd);
		return (126);
	}
	else if (access(*p, X_OK) == -1)
	{
		printf("%s: command not found\n", cmd);
		return (127);
	}
	return (0);
}

static char	**find_path(t_pathAndEnv *env)
{
	char	*p;
	char	**path;
	int		i;

	i = 0;
	p = NULL;
	if (env->path == false)
		p = ft_strdup("/usr/local/sbin:/usr/local/bin:/usr/sbin"
				":/usr/bin:/sbin:/bin");
	else
	{
		while (env->envp[i])
		{
			if (ft_strncmp(env->envp[i], "PATH=", 4) == 0)
			{
				p = ft_strchr(env->envp[i], '=');
				if (p)
					p++;
				break ;
			}
			i++;
		}
	}
	path = ft_split(p, ':');
	return (path);
}

static void	join_path(char **path, char **p, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (*p)
			free (*p);
		*p = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(*p, X_OK) == -1)
			i++;
		else
			break ;
	}
}

int	check_path(char *cmd, char **p, t_pathAndEnv *env)
{
	char	**path;
	int		i;

	if (cmd == NULL)
		cmd = ft_strdup(" ");
	if (ft_strchr(cmd, '/') || cmd[0] == '.')
		return (handle_path1(cmd, p));
	*p = NULL;
	path = find_path(env);
	if (!path)
		return (handle_path_err(p, cmd));
	join_path(path, p, cmd);
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	return (handle_path_err(p, cmd));
}
