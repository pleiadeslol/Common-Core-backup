/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:54:17 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/09 17:55:59 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "ft_eprintf/ft_eprintf.h"

typedef struct s_args
{
	char	*file1;
	char	*file2;
	char	***cmd;
	char	**path;
	int		fd1;
	int		fd2;
	int		count;
	char	*limiter;
}	t_args;

t_args	*set_args(int ac, char **av, char **envp);
void	check_args(t_args *args, char **envp);
void	check_cmd(t_args *args, char **envp);
void	check_files(t_args *args);
void	exec_cmd(t_args *args, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strtrim(char const *s1, char const *s2);
void	replace_home(char **args, char **envp);
char	**find_path(char **envp);
int		check_path(char *cmd, char **p, char **envp);
void	free_str(char **str);
void	first_cmd(int fd1, int pipe);
void	last_cmd(int fd2, int pipe);
void	middle_cmd(int pipe1, int pipe2);
void	close_pipe(t_args *args, int **pipe_fd);
void	exec_child(t_args *args, int **pipe_fd, int i, char **envp);
void	create_pipe(t_args *args, int **pipe_fd);
t_args	*here_args(char **av, char **envp);
void	here_check(t_args *args, char **envp);
void	here_doc(t_args *args);
void	free_pipex(t_args *args);

#endif