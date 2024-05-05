/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:54:17 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/05 01:41:57 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"

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

t_args	*set_args(int ac, char **av, char *p);
void	check_args(t_args *args);
int		check_files(t_args *args);
void	exec_cmd(t_args *args);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *s, char c);

#endif