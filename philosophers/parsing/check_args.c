/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:47:08 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/24 17:38:04 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Error: 5 or 6 arguments needed\n");
		return (0);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Error: argument needs to be a number\n");
				return (0);
			}
			j++;
		}
		i++;
	}
}
