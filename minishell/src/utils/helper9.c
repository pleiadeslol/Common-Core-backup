/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:10:22 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/13 19:10:38 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*ft_strjoin_2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*join;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	while (s1[j])
	{
		join[i] = s1[j];
		j++;
		i++;
	}
	ft_fill_rest(s2, join, i);
	free(s1);
	return (join);
}

int	is_builtin(char *s)
{
	char	*tmp;

	if (empty_string(s))
		return (0);
	tmp = ft_strtrim(s, "\'\"");
	if (ft_strncmp(tmp, "echo", 5) == 0
		|| ft_strncmp(tmp, "cd", 3) == 0
		|| ft_strncmp(tmp, "pwd", 4) == 0
		|| ft_strncmp(tmp, "export", 7) == 0
		|| ft_strncmp(tmp, "unset", 6) == 0
		|| ft_strncmp(tmp, "env", 4) == 0
		|| ft_strncmp(tmp, "exit", 5) == 0)
		return (free(tmp), 1);
	return (free(tmp), 0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static unsigned int	ft_count_digits(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	len;

	len = ft_count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}
