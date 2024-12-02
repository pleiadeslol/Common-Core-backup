/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:10:53 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/13 19:20:51 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup(char *s, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*dup;

	slen = ft_strlen(s);
	i = 0;
	dup = (char *) ft_calloc(sizeof(char), (slen + 1));
	if (!dup)
		return (NULL);
	while (s[i] && i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	set_env(t_env **envp, char *var, char *value)
{
	t_env	*tmp;
	int		found;

	tmp = *envp;
	found = 0;
	while (*envp)
	{
		if (ft_strcmp((*envp)->var, var) == 0)
		{
			if ((*envp)->value)
				free((*envp)->value);
			(*envp)->value = ft_strjoin("=", value);
			found = 1;
		}
		*envp = (*envp)->next;
	}
	*envp = tmp;
	if (found != 1)
	{
		value = ft_strjoin("=", value);
		ft_envadd_back(envp, ft_envnew(var, value));
		free(value);
	}
}

char	**get_env(t_env *envp)
{
	char	**env;
	int		size;
	int		i;

	size = ft_envsize(envp);
	env = ft_calloc(sizeof(char *), size + 1);
	i = 0;
	while (envp)
	{
		env[i] = ft_strjoin(envp->var, envp->value);
		envp = envp->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}

char	*ft_replace_char(char *s)
{
	char	*dup;
	char	*rslt;

	dup = ft_strdup(s + 1);
	rslt = ft_strjoin(g_global->status, dup);
	free(dup);
	return (rslt);
}
