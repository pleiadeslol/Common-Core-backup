/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:37:19 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/12 20:57:10 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		write (STDOUT_FILENO, env[i], ft_strlen(env[i]));
		write (STDOUT_FILENO, "\n", 1);
		i++;
	}
	set_status(0);
}
