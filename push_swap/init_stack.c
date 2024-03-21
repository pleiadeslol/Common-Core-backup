/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:16:46 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/21 02:16:46 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int ac, char **av)
{
	int     i;
	t_stack **s;

	i = 1;
	while(av[i])
	{
		ft_lstnew();
		s->value = ft_atoi(av[i]);
	}
}
