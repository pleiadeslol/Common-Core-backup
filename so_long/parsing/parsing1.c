#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int check_ber(char *str)
{
	int i = 0;
	if (ft_strchr1(str, '.') && ft_strchr1(str, 'b') && ft_strchr1(str, 'e') && ft_strchr1(str, 'r'))
		return (1);
	else
		return (0);
}

int check_len(char **str)
{
	int i = 0;
	int count = ft_strlen(str[0]);
	while (str[i])
	{
		if (count != ft_strlen(str[i]))
			return 0;
		i++;
	}
	return 1;
}

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

