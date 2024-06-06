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
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	int		fd1;
	int		fd2;
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
void	replace_home(t_args *args, char **envp);
char	**find_path(char **envp);
int		check_path(char *cmd, char **p, char **envp);
void	free_str(char **str);
void	free_pipex(t_args *args);
char	*ft_strchr(const char *s, int c);

#endif