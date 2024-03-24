/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:18:57 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/24 01:51:48 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_stack **a, t_stack **b)
{
	// check instructions
	if (check_sorted(a) && ft_lstsize(b) == 0)
		return (1);
	else
		return (0);
}

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
	if (checker(&a, &b) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
