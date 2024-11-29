/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:28:43 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/29 03:01:40 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_export(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '_')
			i++;
		if (ft_isdigit(str[0]) || !ft_isalnum(str[i]))
		{
			printf("minishell: export: not a valid identifier\n");
			set_status(1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	set_status(int status_code)
{
	free(g_global->status);
	g_global->status = ft_itoa(status_code);
}
