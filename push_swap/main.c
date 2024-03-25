/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:33:36 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/25 05:10:18 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 2)
		av = handle_av(av);
	if (!handle_errors(av))
	{
		if (ac == 2)
			free_av(av);
		return (0);
	}
	a = init_stack(av);
	if (!check_sorted(a))
		sort(&a, &b);
	return (0);
}
