/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:37:03 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/27 14:49:02 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(int ac, char **av, char **envp)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	args->cmd = malloc(sizeof(char **) * 3);
	args->path = malloc(sizeof(char **) * 3);
	args->file
}