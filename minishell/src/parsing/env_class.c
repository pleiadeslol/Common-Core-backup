/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:09 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/13 20:50:57 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_env	*ft_envnew(char *var, char *value)
{
	t_env	*list;

	list = (t_env *)malloc (sizeof(t_env));
	if (!list)
		return (0);
	list->var = ft_strdup(var);
	list->value = ft_strdup(value);
	list->next = 0;
	return (list);
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*curr;

	if (!new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

int	ft_envsize(t_env *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_env	*empty_env(t_env **first)
{
	char	s[100];

	set_env(first, "PWD", getcwd(s, 100));
	set_env(first, "SHLVL", "1");
	return (*first);
}

t_env	*struct_env(char **envp)
{
	t_env	*first;
	char	*var;
	char	*value;
	int		i;
	int		j;

	i = 0;
	first = NULL;
	if (!*envp)
		return (empty_env(&first));
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		var = ft_substr(envp[i], 0, j);
		value = ft_strdup(envp[i] + j);
		ft_envadd_back(&first, ft_envnew(var, value));
		free(var);
		free(value);
		i++;
	}
	return (first);
}
