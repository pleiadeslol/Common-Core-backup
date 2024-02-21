#include "headers/so_long.h"
#include "headers/get_next_line.h"

void	fill_c(char **tab, t_point size, t_point cur, int *count, int req_c)
{
	if (req_c == *count || cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == 'E' || tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'V')
		return;
	if (tab[cur.y][cur.x] == 'C')
		(*count)++;
	tab[cur.y][cur.x] = 'V';
	if (req_c == *count)
		return;
	fill_c(tab, size, (t_point){cur.x - 1, cur.y}, count, req_c);
	fill_c(tab, size, (t_point){cur.x + 1, cur.y}, count, req_c);
	fill_c(tab, size, (t_point){cur.x, cur.y - 1}, count, req_c);
	fill_c(tab, size, (t_point){cur.x, cur.y + 1}, count, req_c);
}

void    fill_e(char **tab, t_point size, t_point cur, int *count)
{

    if (*count == 1 || cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'V')
		return;
	if (tab[cur.y][cur.x] == 'E')
	{

		(*count)++;
	}
	tab[cur.y][cur.x] = 'V';
	if (*count == 1)
		return ;
	fill_e(tab, size, (t_point){cur.x - 1, cur.y}, count);
	fill_e(tab, size, (t_point){cur.x + 1, cur.y}, count);
	fill_e(tab, size, (t_point){cur.x, cur.y - 1}, count);
	fill_e(tab, size, (t_point){cur.x, cur.y + 1}, count);
}

void flood_fill(char **tab1, char **tab2, t_point size, t_point cur, int req_c)
{
	int count;
	int i = 0;
	count = 0;
	fill_c(tab1, size, cur, &count, req_c);
	if (req_c != count)
		printf("Error\nInvalid path\n");
	else
	{
		count = 0;
		fill_e(tab2, size, cur, &count);
		if (count == 0)
			printf("Error\nInvalid path\n");
	}
	free_str(tab1);
	free_str(tab2);
}
