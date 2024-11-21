/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper12.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:51:45 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/13 19:51:47 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_lstsize(t_cmd *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_envdelone(t_env *lst)
{
	if (!lst)
		return ;
	free(lst->var);
	free(lst->value);
	free(lst);
}

void	ft_envclear(t_env **lst)
{
	t_env	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_envdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_clear_path_env(t_pathAndEnv **lst)
{
	int	i;

	i = 0;
	while ((*lst)->envp[i])
	{
		free((*lst)->envp[i]);
		i++;
	}
	free((*lst)->envp);
	free(*lst);
}

void	ft_redirdelone(t_redir *lst)
{
	if (!lst)
		return ;
	free(lst->file);
	free(lst->heredoc);
	free(lst);
}
