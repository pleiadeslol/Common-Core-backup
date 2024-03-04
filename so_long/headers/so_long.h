/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:32:51 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/03/04 22:40:28 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>

# define HEIGHT 1080
# define WIDTH 1920
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define S 1
# define D 2
# define A 0
# define ESC 53

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_collec
{
	int	count;
	int	req_c;
}	t_collec;

typedef struct s_map
{
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*player;
	void	*exit;
}	t_map;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	char	**map;
	t_map	*img;
	int		moves;
}	t_mlx;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strtrim(char const *s1, char const *s2);
char	*ft_strcpy(char *s1, char *s2);
int		count_line(int fd);
int		check_ber(char *str);
int		check_len(char **str, int count);
int		check_corners(char **str, int len);
int		check_walls(char **str, int count);
int		check_e(char **str);
int		check_c(char **str);
int		check_p(char **str);
int		check_char(char **str);
void	trim_line(char **str, int count, int fd, char *line);
char	**copy_str(char *av, int count);
void	free_str(char **str);
void	fill_c(char **tab, t_point size, t_point cur, t_collec *c);
void	fill_e(char **tab, t_point size, t_point cur, int *count);
int		flood_fill(char **tab1, char **tab2, t_point size, t_point cur);
int		av_errors(int ac, char **av);
int		map_errors1(char **str, int count);
int		map_errors2(char **str);
int		map_errors3(char **av, char **str, int count);
t_point	find_cur(char **str);
t_point	find_size(char **str);
int		errors(int ac, char **av, char **str, int count);
void	draw_game(t_mlx *mlx, int count);
int		draw_map(t_mlx *mlx);
void	mlx_image_win(t_mlx *mlx, void *map, int j, int i);
void	*mlx_xpm_img(void *ptr, char *path);
int		move_player(int keycode, void *mlx);
int		exit_mlx(void	*mlx);
void	free_game(t_mlx *mlx, t_map *map);
void	handle_action(t_mlx *mlx, t_collec c, t_point p, t_point pos);

#endif