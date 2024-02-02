/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:11:30 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/02 23:43:45 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// the map must be closed/surrounded bt walls
int	check_walls(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(   ))
	}
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
