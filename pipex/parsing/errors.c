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
	args->fd2 = fd2;
}

int	check_cmd(t_args *args, char **envp)
{
	check_path(args->cmd1[0], &args->path1, envp);
	if (check_path(args->cmd2[0], &args->path2, envp) == 0)
		return (0);
	return (1);
}

void	check_args(t_args *args, char **envp)
{
	check_files(args);
	if (!check_cmd(args, envp))
		exit(127);
}
