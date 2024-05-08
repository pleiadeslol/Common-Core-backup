/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:22:43 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/07 23:51:32 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_args *args, int id)
{
	pid	id;
	int	pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		exit (0);
	id = fork();
	if (id == 0)
	{
		execv(args->path1, args->cmd1);
	}
	else
		execv(args->path2, args->cmd2);
}
