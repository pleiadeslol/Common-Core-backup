/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:54:17 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/04/26 18:24:54 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_args
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	int		fd1;
	int		fd2;
}	t_args;

t_args	*set_args(int ac, char **av);
void	check_args(t_args *args);
int		check_files(t_args *args);

#endif