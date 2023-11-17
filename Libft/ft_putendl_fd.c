/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:18:08 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/15 16:25:33 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/**#include <fcntl.h>

int main()
{
	char *s1 = "hiii";
	int fd = open("test.txt", O_CREAT | O_WRONLY);
	ft_putstr_fd(s1, fd);
	char *s2 = "hi again!";
	ft_putendl_fd(s2, fd);
	return 0;
}**/