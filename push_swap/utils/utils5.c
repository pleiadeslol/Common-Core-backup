/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 04:25:53 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/04/06 03:24:37 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_sort_array(t_stack *a)
{
	int	*arr;
	int	size;
	int	i;

	size = ft_lstsize(a);
	arr = malloc(sizeof(int) * size);
	i = 0;
	while (a != NULL)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
	bubble_sort(arr, size);
	return (arr);
}

void	set_index(t_stack *a, int *array_sorted)
{
	int	i;
	int	size;

	size = ft_lstsize(a);
	while (a != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == array_sorted[i])
				a->index = i;
			i++;
		}
		a = a->next;
	}
}

void	check_index(t_stack **a, int i, int proxime)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index <= i || tmp->index <= i + proxime)
			break ;
		j++;
		tmp = tmp->next;
	}
	if (j < ft_lstsize(*a) / 2)
		ra(a);
	else
		rra(a);
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = NULL;
	while (a)
	{
		tmp = a;
		free(a);
		a = tmp->next;
	}
}

void	ft_rotate_a_b(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
