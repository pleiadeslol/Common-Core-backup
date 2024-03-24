/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 04:34:49 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/23 17:29:58 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    split_a(t_stack **a, t_stack **b)
{
    int half;

    half = ft_lstsize(*a) / 2;
    while (half)
    {
        pb(a, b);
        half--;
    }
}

void	sort_one_h(t_stack **a, t_stack **b)
{
	split_a(a, b);
}
