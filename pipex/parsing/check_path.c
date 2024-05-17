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

char	**find_path(char **envp)
{
	char	*p;
	char	**path;
	int		i;

	i = 0;
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

void	check_path(char *cmd, char **p, char **envp)
{
	int		i;
	char	*tmp;
	char	**path;

	i = 0;
	path = find_path(envp);
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == -1)
		{
			ft_eprintf("permission denied: %s\n", cmd);
			free_str(path);
			exit(126);
		}
		if (access(cmd, X_OK) == -1)
		{
			ft_eprintf("command not found: %s\n", cmd);
			free_str(path);
			exit (127);
		}
		*p = cmd;
		free_str(path);
		return ;
	}
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		*p = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(*p, X_OK) == -1)
			i++;
		else
			break ;
	}
	free_str(path);
	if (access(*p, F_OK) == 0 && access(*p, X_OK) == -1)
	{
		ft_eprintf("permission denied: %s\n", cmd);
		free(*p);
		exit(126);
	}
	if (access(*p, X_OK) == -1)
	{
		ft_eprintf("command not found: %s\n", cmd);
		free(*p);
		exit (127);
	}
}
