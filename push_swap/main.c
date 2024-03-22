/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:08:14 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 03:08:14 by rzarhoun         ###   ########.fr       */
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
		av = handle_av(ac, av);
	if (!handle_errors(ac, av))
	{
		if (ac == 2)
			free_av(av);
		return (0);
	}
	a = init_stack(av);
	if (!check_sorted(a))
	{
		// sort it !!
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else if (ft_lstsize(a) == 4)
			sort_four(&a, &b);
		else if (ft_lstsize(a) == 5)
			sort_five(&a, &b);
	}
	t_stack *tmpa = a;
	while(tmpa != NULL)
	{
		printf("%d\n", tmpa->value);
		tmpa = tmpa->next;
	}
	return (0);
}
