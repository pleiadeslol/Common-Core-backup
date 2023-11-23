# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 21:41:21 by rzarhoun          #+#    #+#              #
#    Updated: 2023/11/23 20:19:53 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_putnbr_u.c \
		ft_strlen.c \
		ft_print_ptr.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putstr.c

OBJ = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a 

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re