/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:30:32 by rzarhoun          #+#    #+#             */
/*   Updated: 2023/11/23 14:08:04 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_ptr(unsigned long p);
void	ft_putnbr(int n);
void	ft_puthex(unsigned int n);
void	ft_puthexu(unsigned int n);
void	ft_putnbr_u(unsigned int n);
size_t	ft_strlen(const char *str);

#endif