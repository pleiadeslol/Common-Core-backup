/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 01:18:57 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/04/05 23:44:26 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

void	checker(t_stack **a, t_stack **b)
{
	if (check_sorted(*a) && ft_lstsize(*b) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

void	sort_stack(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		ft_push(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push(b, a);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rotate_a_b(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_swap_a_b(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse_rotate(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse_rotate(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_reverse_rotate_a_b(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

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
	line = get_next_line(0);
	while (line)
	{
		sort_stack(&a, &b, line);
		line = get_next_line(0);
	}
	checker(&a, &b);
	return (0);
}
