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

void flood_fill(char **tab, t_point size, t_point cur, int req_c)
{
	int count;
	int i = 0;
	count = 0;
	fill_c(tab, size, cur, &count, req_c);
	if (req_c != count)
		printf("Error\nNo valid path\n");
}
