/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper16.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:15 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/16 01:33:17 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	check_unclosed_quote_helper(char *line, int *i, int *count, char c)
{
	*i += 1;
	*count += 1;
	while (line[*i] && line[*i] != c)
		(*i)++;
	if (line[*i] && line[*i] == c)
		*count += 1;
}

int	check_unclosed_quote(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] && line[i] == '\'')
			check_unclosed_quote_helper(line, &i, &count, '\'');
		if (line[i] && line[i] == '\"')
			check_unclosed_quote_helper(line, &i, &count, '\"');
		if (!line[i])
			break ;
		i++;
	}
	return (count);
}

int	ft_parse_line1(char *line)
{
	if (ft_space_string(line) == 1)
		return (-1);
	if (line[0] == '|')
	{
		printf("minishell: parse error near `|'\n");
		return (-1);
	}
	if (check_unclosed_quote(line) % 2 != 0)
	{
		printf("minishell: unclosed quote\n");
		return (-1);
	}
	return (0);
}

int	ft_parse_line2(char *line, int i)
{
	if (line[i + 1] == '|')
	{
		printf("minishell: parse error near `|'\n");
		return (-1);
	}
	else if (line[i + 1] == '<' && line[i + 2] == '<')
	{
		printf("minishell: parse error near `<'\n");
		return (-1);
	}
	return (0);
}

int	parse_line(char *line)
{
	int	i;

	i = 0;
	if (ft_parse_line1(line) != 0)
		return (-1);
	while (line[i])
	{
		if (ft_help_parse(line, &i, '\'') == 0
			|| ft_help_parse(line, &i, '\"') == 0)
			return (0);
		if (line[i] == '<' && ft_parse_line2(line, i) != 0)
			return (-1);
		else if (line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '>')
			return (printf("minishell: parse error near `>'\n"), -1);
		else if (line[i] == '|')
		{
			i += 1;
			while (line[i] == ' ')
				i++;
			if (!line[i] || line[i] == '|')
				return (printf("minishell: parse error near `|'\n"), -1);
		}
		i++;
	}
	return (0);
}
