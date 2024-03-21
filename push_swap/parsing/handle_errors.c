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

int	check_param(int ac)
{
	if (ac <= 1)
	{
		write(2, "Error\nNo arguments\n", 19);
		return (0);
	}
	return (1);
}

int	check_limit(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) > 2147483647)
		{
			write(2, "Error\nAn argument is bigger than Int Max\n", 41);
			return (0);
		}
		else if (ft_atoi(av[i]) < -2147483648)
		{
			write(2, "Error\nAn argument is less than Int Min\n", 39);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_type(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!ft_isdigit(av[i][j]))
			{
				write(2, "Error\nAn argument isn't an integer\n", 35);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				write(2, "Error\nThere is a double\n", 24);
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
	if (!check_param(ac) || !check_double(av) || !check_type(av)
		|| !check_limit(av))
		return (0);
	return (1);
}
