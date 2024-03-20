/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:01:21 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/19 22:22:07 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long_bonus.h"
#include "headers/get_next_line.h"
#include "ft_printf/ft_printf.h"

void	fill_c(char **tab, t_point size, t_point cur, t_collec *c)
{
	if (c->req_c == c->count || cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == 'E'
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'V')
		return ;
	if (tab[cur.y][cur.x] == 'C')
		(c->count)++;
	tab[cur.y][cur.x] = 'V';
	if (c->req_c == c->count)
		return ;
	fill_c(tab, size, (t_point){cur.x - 1, cur.y}, c);
	fill_c(tab, size, (t_point){cur.x + 1, cur.y}, c);
	fill_c(tab, size, (t_point){cur.x, cur.y - 1}, c);
	fill_c(tab, size, (t_point){cur.x, cur.y + 1}, c);
}

void	fill_e(char **tab, t_point size, t_point cur, int *count)
{
	if (*count == 1 || cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == '1'
		|| tab[cur.y][cur.x] == 'V')
		return ;
	if (tab[cur.y][cur.x] == 'E')
		(*count)++;
	tab[cur.y][cur.x] = 'V';
	if (*count == 1)
		return ;
	fill_e(tab, size, (t_point){cur.x - 1, cur.y}, count);
	fill_e(tab, size, (t_point){cur.x + 1, cur.y}, count);
	fill_e(tab, size, (t_point){cur.x, cur.y - 1}, count);
	fill_e(tab, size, (t_point){cur.x, cur.y + 1}, count);
}

int	flood_fill(char **tab1, char **tab2, t_point size, t_point cur)
{
	int			i;
	t_collec	c;

	c.count = 0;
	c.req_c = check_c(tab1);
	i = 0;
	fill_c(tab1, size, cur, &c);
	if (c.req_c != c.count)
	{
		printf("Error\nInvalid path\n");
		return (free_str(tab1), 0);
	}
	else
	{
		c.count = 0;
		fill_e(tab2, size, cur, &c.count);
		if (c.count == 0)
		{
			ft_printf("Error\nInvalid path\n");
			return (free_str(tab1), free_str(tab2), 0);
		}
	}
	return (free_str(tab1), free_str(tab2), 1);
}
