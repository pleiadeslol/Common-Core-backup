/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:07 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/09/23 03:29:22 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*args;
	int		status;

	check_args(ac, av);
	args = parse_data(ac, av);
	if (!args)
		return (EXIT_FAILURE);
	status = create_forks(args);
	if (status == 0)
		return (EXIT_FAILURE);
	status = init_philo(args);
	if (!status)
		return (EXIT_FAILURE);
	status = run_philo(args);
	if (!status)
		return (EXIT_FAILURE);
}
