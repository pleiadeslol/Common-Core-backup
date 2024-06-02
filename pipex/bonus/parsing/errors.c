/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:24:38 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/07 16:56:42 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h" 
#include "../get_next_line/get_next_line.h"

void	check_files(t_args *args)
{
	int	fd1;
	int	fd2;

	fd1 = open(args->file1, O_RDONLY);
	args->fd1 = fd1;
	if (fd1 < 0)
	{
		ft_eprintf("no such file or directory: %s\n", args->file1);
	}
	fd2 = open(args->file2, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd2 < 0)
	{
		ft_eprintf("permission denied: %s\n", args->file2);
		free_pipex(args);
		exit(1);
	}
	args->fd2 = fd2;
}

void	check_cmd(t_args *args, char **envp)
{
	int	i;

	i = 0;
	while (i < args->count - 1)
	{
		check_path(args->cmd[i][0], &args->path[i], envp);
		i++;
	}
	i = check_path(args->cmd[i][0], &args->path[i], envp);
	if (i == 126)
	{
		free_pipex(args);
		exit (126);
	}
	else if (i == 127)
	{
		free_pipex(args);
		exit (127);
	}
}

void	check_args(t_args *args, char **envp)
{
	check_files(args);
	check_cmd(args, envp);
}
