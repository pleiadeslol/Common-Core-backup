/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:44:17 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/30 20:49:22 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	handle_path1(char *cmd, char **p)
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

int	handle_path_err(char **p, char *cmd)
{
	if (access(*p, F_OK) == 0 && access(*p, X_OK) == -1)
	{
		printf("%s: permission denied\n", cmd);
		return (126);
	}
	else if (access(*p, X_OK) == -1)
	{
		printf("%s: No such file or directory\n", cmd);
		return (127);
	}
	return (0);
}

int	handle_path_err1(char **p, char *cmd)
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
