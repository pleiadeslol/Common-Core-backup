#include "includes/gnl.h"

/**void map_parsing(int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((line = get_next_line(fd)))
	{
		while (line[i])
		{
			if (line[i] == '1')
				draw_wall();
			else if (line[i] == '0')
				draw_floor();
			else if (line[i] == 'P')
				draw_player();
			else if (line[i] == 'C')
				draw_collectible();
			else if (line[i] == 'E')
				draw_exit();
			else
				error();
			i++;
		}
		j++;
	}
}**/

