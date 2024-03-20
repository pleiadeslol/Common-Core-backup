/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:58:06 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/12 14:58:06 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_param(int ac)
{
	if (ac <= 1)
	{
		printf("Error\nNo arguments\n");
		return (0);
	}
	return (1);
}

int check_type(char **av)
{
	int	i;
	int	j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Error\nAn argument isn't an integer\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_double(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while(av[i])
	{
		j = i + 1;
		while(av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				printf("Error\nThere is a double\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	handle_errors(int ac, char **av)
{
	if (!check_param(ac) || !check_double(av) || !check_type(av))
		return (0);
	return (1);
}