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

void	run_unset(char	***env, char *str)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	if (find_env((*env), str))
	{
		while ((*env)[i])
		{
			key = get_key((*env)[i]);
			if (ft_strcmp(key, str) == 0)
			{
				(free(key), free((*env)[i]));
				j = i;
				while ((*env)[j])
				{
					(*env)[j] = (*env)[j + 1];
					j++;
				}
				break ;
			}
			(free(key), i++);
		}
	}
	set_status(0);
}

void	ft_unset(t_args *args, char ***env)
{
	if (!args)
		return ;
	while (args)
	{
		run_unset(env, args->word);
		args = args->next;
	}
}
