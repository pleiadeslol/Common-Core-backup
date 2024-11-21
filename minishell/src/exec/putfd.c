/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:50:14 by root              #+#    #+#             */
/*   Updated: 2024/11/18 00:50:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (s)
	{
		count = ft_putstr_fd(s, fd);
		count += ft_putchar_fd('\n', fd);
	}
	return (count);
}
