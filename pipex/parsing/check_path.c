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

int	check_path(char *cmd, char **p, char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = find_path(envp);
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		*p = ft_strjoin(path[i], cmd);
		if (access(*p, X_OK) == -1)
			i++;
		else
			break ;
	}
	if (access(*p, X_OK) == -1)
	{
		ft_eprintf("command not found: %s\n", cmd);
		return (0);
	}
	return (1);
}
