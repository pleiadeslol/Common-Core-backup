/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:17:10 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/10 01:48:20 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*find_env(char **env, char *str)
{
	char	*p;
	int		i;

	i = 0;
	p = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0)
		{
			p = ft_strchr(env[i], '=');
			if (p)
				p++;
			break ;
		}
		i++;
	}
	return (p);
}
