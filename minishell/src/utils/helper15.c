/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper15.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 06:02:46 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/14 06:02:48 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	find(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i += 1;
			if (s[i] && (ft_isalnum(s[i]) || s[i] == '?' || s[i] == '_'))
				count++;
		}
		i++;
	}
	return (count);
}

int	find1(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	find_emptycmd(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		if (ft_strlen(s) == 2)
			return (1);
		i += 1;
		while (s[i] && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
			i++;
		if (s[i] == '\'' && !s[i + 1])
			return (1);
	}
	i = 0;
	if (s[i] == '\"' && s[ft_strlen(s) - 1] == '\"')
	{
		if (ft_strlen(s) == 2)
			return (1);
		i += 1;
		while (s[i] && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
			i++;
		if (s[i] == '\"' && !s[i + 1])
			return (1);
	}
	return (0);
}

int	len_env_var(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '=')
		i++;
	return (i);
}
