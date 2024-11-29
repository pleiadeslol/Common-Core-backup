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
	char	pwd[100];

	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		printf("Error: Unable to get current working directory\n");
		set_status(1);
		return ;
	}
	printf("%s\n", pwd);
	set_status(0);
}
