# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 21:41:21 by rzarhoun          #+#    #+#              #
#    Updated: 2024/05/14 03:09:20 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_eprintf.c \
		ft_eputchar.c \
		ft_eputnbr_u.c \
		ft_strlen.c \
		ft_eprint_ptr.c \
		ft_eputhex.c \
		ft_eputnbr.c \
		ft_eputstr.c \
		ft_strchr.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libfteprintf.a 

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re