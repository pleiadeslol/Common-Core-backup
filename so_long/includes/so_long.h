/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:32:51 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/02/06 16:24:06 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(const char *s1, const char *s2);
int check_ber(char *str);
int check_len(char **str);
int check_walls(char **str);
int	check_e(char **str);
int	check_c(char **str);
int	check_p(char **str);
int	check_char(char **str);

#endif