/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:30:32 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/14 03:19:35 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EPRINTF_H
# define FT_EPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# define HEX "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

int		ft_eprintf(const char *str, ...);
void	ft_putchar(char c, int *ptr);
void	ft_putstr(char *str, int *ptr);
void	ft_print_ptr(unsigned long p, int *ptr);
void	ft_putnbr(int n, int *ptr);
void	ft_puthex(unsigned long n, char x, int *ptr);
void	ft_putnbr_u(unsigned int n, int *ptr);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);

#endif