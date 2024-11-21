/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:07:03 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/10/09 22:28:31 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_pwd(void)
{
	char	*s;
	char	*pwd;

	s = NULL;
	pwd = getcwd(s, 0);
	printf("%s\n", pwd);
	free(s);
	free(pwd);
	set_status(0);
}
