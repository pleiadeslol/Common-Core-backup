/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:40:30 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/06/01 22:16:35 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../get_next_line/get_next_line.h"

void	create_pipe(t_args *args, int **pipe_fd)
{
	int	i;

	i = 0;
	while (i < args->count - 1)
	{
		pipe_fd[i] = malloc(sizeof(int) * 2);
		if (pipe(pipe_fd[i]) == -1)
			exit(1);
		i++;
	}
}
