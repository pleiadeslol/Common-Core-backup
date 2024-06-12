/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:49:13 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/07 16:56:57 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h" 
#include "../get_next_line/get_next_line.h"
#include "../ft_eprintf/ft_eprintf.h"

static int	handle_path1(char *cmd, char **p)
{
	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == -1)
	{
		ft_eprintf("permission denied: %s\n", cmd);
		return (126);
	}
	if (access(cmd, X_OK) == -1)
	{
		ft_eprintf("command not found: %s\n", cmd);
		return (127);
	}
	*p = ft_strdup(cmd);
	return (0);
}

static int	handle_path_err(char **p, char *cmd)
{
	if (access(*p, F_OK) == 0 && access(*p, X_OK) == -1)
	{
		ft_eprintf("permission denied: %s\n", cmd);
		return (126);
	}
	else if (access(*p, X_OK) == -1)
	{
		ft_eprintf("command not found: %s\n", cmd);
		return (127);
	}
	return (1);
}

char	**find_path(char **envp)
{
	char	*p;
	char	**path;
	int		i;

	i = 0;
	p = NULL;
	path = NULL;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 4) == 0)
		{
			p = ft_strchr(envp[i], '=');
			if (p)
				p++;
			break ;
		}
		i++;
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

int	check_path(char *cmd, char **p, char **envp)
{
	char	**path;

	if (cmd == NULL)
		cmd = ft_strdup(" ");
	if (cmd[0] == '/' || cmd[0] == '.')
		return (handle_path1(cmd, p));
	*p = NULL;
	path = find_path(envp);
	if (!path)
		return (handle_path_err(p, cmd));
	join_path(path, p, cmd);
	free_str(path);
	return (handle_path_err(p, cmd));
}
