/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:44:56 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/14 01:07:35 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	check_export(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
		{
			j = i + 1;
			while (str[j])
			{
				if (str[j] == '=')
				{
					printf("minishell: export: not a valid identifier\n");
					set_status(1);
					return ;
				}
				j++;
			}
		}
		i++;
	}
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	key = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str && str[i])
	{
		key[i] = str[i];
		if (str[i] == '=')
			break ;
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*get_value(char *str, t_pathAndEnv **pEnv)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	i++;
	if (str[i] == ' ')
		return (ft_strdup(""));
	value = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	j = 0;
	while (str && str[i])
	{
		value[j] = str[i];
		j++;
		i++;
	}
	value[j] = '\0';
	expand_2(&value, (*pEnv)->envp);
	return (value);
}

void	new_value(t_pathAndEnv **pEnv, char *str)
{
	int		i;
	int		j;
	char	**new_env;

	check_str(str);
	j = 0;
	while ((*pEnv)->envp[j])
		j++;
	new_env = malloc(sizeof(char *) * (j + 2));
	i = 0;
	while (i < j)
	{
		new_env[i] = ft_strdup((*pEnv)->envp[i]);
		i++;
	}
	new_env[i++] = ft_strdup(str);
	new_env[i++] = NULL;
	ft_env_ro(pEnv);
	(*pEnv)->envp = new_env;
}

void	ft_export(t_pathAndEnv **pEnv, char *str)
{
	int		i;
	char	*key;
	char	*value1;

	i = 0;
	if (!str)
	{
		while ((*pEnv)->envp[i])
			printf("declare -x %s\n", (*pEnv)->envp[i++]);
		set_status(0);
		return ;
	}
	if (!ft_strchr(str, '='))
		return ;
	check_export(str);
	key = get_key(str);
	value1 = get_value(str, pEnv);
	if (key)
		update_env(pEnv, key, value1);
	else
		new_value(pEnv, str);
	(free(key), free(value1), set_status(0));
}
