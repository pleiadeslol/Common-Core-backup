/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:44:56 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/14 01:24:33 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_unset(char	***env, char *str)
{
	int		i;
	int		j;

	i = 0;
	if (!str)
		return ;
	if (find_env((*env), str))
	{
		while ((*env)[i])
		{
			if (ft_strncmp((*env)[i], str, ft_strlen(str)) == 0)
			{
				free((*env)[i]);
				j = i;
				while ((*env)[j])
				{
					(*env)[j] = (*env)[j + 1];
					j++;
				}
				break ;
			}
			i++;
		}
	}
	set_status(0);
}
