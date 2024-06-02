/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:37:03 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/06/02 19:54:24 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_args	*here_args(char **av, char **envp)
{
	t_args	*args;
	int		i;
	int		count;

	args = malloc(sizeof(t_args));
	args->count = 2;
	args->cmd = malloc(sizeof(char **) * 3);
	args->path = malloc(sizeof(char **) * 3);
	args->limiter = av[2];
	args->file2 = av[5];
	args->cmd[0] = ft_split(av[3], ' ');
	args->cmd[1] = ft_split(av[4], ' ');
	i = 0;
	count = 2;
	while (count)
	{
		replace_home(args->cmd[i], envp);
		i++;
		count--;
	}
	return (args);
}

void	here_check(t_args *args, char **envp)
{
	int	fd2;
	int	i;

	fd2 = open(args->file2, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd2 < 0)
	{
		ft_eprintf("permission denied: %s\n", args->file2);
		exit(1);
	}
	args->fd2 = fd2;
	check_path(args->cmd[0][0], &args->path[0], envp);
	i = check_path(args->cmd[1][0], &args->path[1], envp);
	if (i == 126)
		exit (126);
	else if (i == 127)
		exit (127);
}

void	here_doc(t_args *args)
{
	int		fd1;
	int		fd2;
	char	*line;
	char	*str;

	fd1 = open("/tmp/file1", O_CREAT | O_TRUNC | O_RDWR, 0644);
	fd2 = open("/tmp/file1", O_CREAT | O_TRUNC | O_RDWR, 0644);
	args->file1 = "file1";
	args->fd1 = fd2;
	line = get_next_line(0);
	str = ft_strtrim(line, "\n");
	while (line)
	{
		if (ft_strncmp(str, args->limiter, ft_strlen(str)) == 0)
			break ;
		write(fd1, str, ft_strlen(str));
		free(line);
		free(str);
		line = get_next_line(0);
		str = ft_strtrim(line, "\n");
	}
	free(line);
	free(str);
	close(fd1);
	unlink("file1");
}
