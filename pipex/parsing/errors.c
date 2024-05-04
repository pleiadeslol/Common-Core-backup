/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:24:38 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/03 23:45:37 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h" 
#include "../get_next_line/get_next_line.h"

int	check_files(t_args *args)
{
	int	fd1;
	int	fd2;

	fd1 = open(args->file1, O_RDONLY);
	args->fd1 = fd1;
	if (fd1 < 0)
	{
		printf("no such file or directory: %s\n", args->file1);
		return (0);
	}
	fd2 = open(args->file2, O_CREAT | O_TRUNC | O_RDWR, 0644);
	args->fd2 = fd2;
	return (1);
}

int	check_cmd(t_args *args)
{
	args->path1 = ft_strjoin("/bin/", args->cmd1);
	if (access(args->path1, X_OK) == -1)
	{
		args->path1 = ft_strjoin("/sbin/", args->cmd1);
		if (access(args->path1, X_OK) == -1)
		{
			printf("command not found: %s\n", args->cmd1);
			return (0);
		}
	}
	args->path2 = ft_strjoin("/bin/", args->cmd2);
	if (access(args->path2, X_OK) == -1)
	{
		args->path2 = ft_strjoin("/sbin/", args->cmd2);
		if (access(args->path2, X_OK) == -1)
		{
			printf("command not found: %s\n", args->cmd2);
			return (0);
		}
	}
	return (1);
}

void	check_args(t_args *args)
{
	if (!check_files(args) || !check_cmd(args))
		exit(0);
}
