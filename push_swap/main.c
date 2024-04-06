/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:33:36 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/04/06 06:43:55 by rzarhoun         ###   ########.fr       */
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
	if (ac == 2)
		free_av(av);
	t_stack *tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	printf("--------------------------------------\n");
	tmp = NULL;
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	if (!a)
		printf("a freed\n");
	if (!b)
		printf("b freed\n");
	system("leaks push_swap");
	return (0);
}
