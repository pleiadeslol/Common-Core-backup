/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper13.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <nalabdal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 04:26:23 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/14 04:56:58 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	has_dq(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			count += 1;
		i++;
	}
	return (count);
}

int	has_sq(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			count += 1;
		i++;
	}
	return (count);
}

int	has_dollar(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '$')
			count += 1;
		i++;
	}
	return (count);
}

void	check_quotes_line_before(t_node **first, char **s)
{
	int		i;
	int		j;
	char	*dup;
	char	**tokens;

	i = 0;
	if (s[i] && find_char(s[i]) == 1)
	{
		dup = add_space(s[i]);
		fill_the_blanks(&dup, '\"');
		fill_the_blanks(&dup, '\'');
		tokens = ft_split(dup, ' ');
		tokens = rev_split(tokens);
		free(dup);
		j = 0;
		while (tokens[j])
		{
			ft_nodeadd_back(first, ft_nodenew(tokens[j]));
			free(tokens[j]);
			j++;
		}
		free(tokens);
	}
	else
		*first = ft_nodenew(s[i]);
}

void	check_pipe_char_line(t_node **first, char **s)
{
	int		i;
	int		j;
	char	*dup;
	char	**tokens;

	i = 1;
	while (s[i])
	{
		if (s[i] && find_char(s[i]) == 1)
		{
			dup = add_space(s[i]);
			fill_the_blanks(&dup, '\"');
			fill_the_blanks(&dup, '\'');
			tokens = ft_split(dup, ' ');
			tokens = rev_split(tokens);
			free(dup);
			j = 0;
			while (tokens[j])
				ft_nodeadd_back(first, ft_nodenew(tokens[j++]));
			free_tab(tokens);
		}
		else
			ft_nodeadd_back(first, ft_nodenew(s[i]));
		i++;
	}
}
