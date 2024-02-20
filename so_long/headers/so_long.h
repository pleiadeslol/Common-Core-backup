/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:32:51 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/20 13:00:11 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>

typedef struct s_point
{
    int x;
    int y;
}       t_point;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strtrim(char const *s1, char const *s2);
int count_line(int fd);
int check_ber(char *str);
int check_len(char **str, int count);
int check_walls(char **str);
int	check_e(char **str);
int	check_c(char **str);
int	check_p(char **str);
int	check_char(char **str);

#endif