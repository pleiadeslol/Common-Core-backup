/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:40:00 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 02:40:00 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char **av)
{
	int		i;
	t_stack	*s;

	i = 1;
	s = malloc(sizeof(t_stack *));
	s = NULL;
	while (av[i])
	{
		ft_lstadd_back(&s, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (s);
}
