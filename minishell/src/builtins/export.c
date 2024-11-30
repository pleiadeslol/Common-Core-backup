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

char	*get_key(char *str)
{
	long	len;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(str, '=');
	len = tmp - str + 1;
	tmp = malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str, len);
	while (tmp[i] == '\'' || tmp[i] == '\"' || tmp[i] == '_')
		i++;
	while (tmp[i])
	{
		if (tmp[i] == '\'' || tmp[i] == '\"' || tmp[i] == '_')
			i++;
		if (ft_isdigit(tmp[0]) || !ft_isalnum(tmp[i]))
		{
			printf("minishell: export: not a valid identifier\n");
			return (set_status(1), NULL);
		}
		i++;
	}
	return (tmp);
}

char	*get_value(char *str, t_pathAndEnv **pEnv)
{
	char	*value;

	value = ft_strchr(str, '=');
	value = ft_strdup(++value);
	if (pEnv)
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

void	run_export(t_pathAndEnv **pEnv, char *str)
{
	char	*key;
	char	*value;

	if (ft_strcmp(str, "") == 0 || str[0] == '=')
	{
		printf("minishell: export: not a valid identifier\n");
		set_status(1);
		return ;
	}
	if (!ft_strchr(str, '='))
	{
		if (find_env((*pEnv)->envp, str) || check_export(str) == 1)
			return ;
		update_env(pEnv, str, "");
		return (set_status(0));
	}
	key = get_key(str);
	if (!key)
		return ;
	value = get_value(str, pEnv);
	if (key)
		update_env(pEnv, key, value);
	else
		new_value(pEnv, str);
	(free(key), free(value), set_status(0));
}

void	ft_export(t_pathAndEnv **env, t_args *args)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	key = NULL;
	value = NULL;
	if (!args)
	{
		while ((*env)->envp[i])
		{
			key = get_key((*env)->envp[i]);
			value = get_value((*env)->envp[i], NULL);
			printf("declare -x %s=\"%s\"\n", key, value);
			(free(key), free(value));
			i++;
		}
		set_status(0);
		return ;
	}
	while (args)
	{
		run_export(env, args->word);
		args = args->next;
	}
}
