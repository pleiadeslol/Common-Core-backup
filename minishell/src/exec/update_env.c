/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:09:51 by root              #+#    #+#             */
/*   Updated: 2024/11/29 02:56:39 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	update_env(t_pathAndEnv **pEnv, char *key, char *value)
{
	t_env	*v;

	v = struct_env((*pEnv)->envp);
	set_env(&v, key, value);
	ft_env_ro(pEnv);
	(*pEnv)->envp = get_env(v);
	ft_envclear(&v);
}

void	update_shlvl(t_pathAndEnv **pEnv)
{
	char	*shlvl;
	char	*value;

	shlvl = getenv("SHLVL");
	if (shlvl)
		value = ft_itoa(ft_atoi(shlvl) + 1);
	else
		value = ft_itoa(1);
	update_env(pEnv, "SHLVL", value);
	free(value);
}
