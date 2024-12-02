/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:17:55 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/04 19:00:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static	int	get_fd(t_redir *redir, char **env)
{
	if (redir->type == 2)
		return (open(redir->file, O_CREAT | O_TRUNC | O_RDWR, 0644));
	else if (redir->type == 3)
		return (open(redir->file, O_RDONLY));
	else if (redir->type == 4)
		return (open(redir->file, O_CREAT | O_APPEND | O_RDWR, 0644));
	else if (redir->type == 5)
		return (here_doc(redir, env));
	return (-1);
}

int	handle_redirections(t_cmd **cmd, char **env)
{
	t_redir	*redir;
	char	*file;

	redir = (*cmd)->redir;
	file = ft_strchr(redir->file, ' ');
	while (redir)
	{

		if (redir->type != 5 && (!ft_strcmp(redir->file, "") || (file && file[1])))
		{
			printf("minishell: ambiguous redirect\n");
			set_status(1);
			return (1);
		}
		redir->fd = get_fd(redir, env);
		if (redir->fd == -1)
		{
			perror("Failed to open file");
			set_status(1);
			return (-1);
		}
		redir = redir->next;
	}
	return (0);
}

void	redirect_fd(t_cmd *cmd)
{
	t_redir	*redir;

	redir = cmd->redir;
	while (redir)
	{
		if (redir->type == 2)
			dup2(redir->fd, STDOUT_FILENO);
		else if (redir->type == 3)
			dup2(redir->fd, STDIN_FILENO);
		else if (redir->type == 4)
			dup2(redir->fd, STDOUT_FILENO);
		else if (redir->type == 5)
			dup2(redir->fd, STDIN_FILENO);
		close(redir->fd);
		redir = redir->next;
	}
}
