# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:18:43 by rzarhoun          #+#    #+#              #
#    Updated: 2023/11/02 16:26:11 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library = libft

files = ft_atoi.c \
       	ft_isascii.c \
	ft_memmove.c \
       	ft_strlcpy.c \
	ft_strrchr.c \
	ft_bzero.c \
     	ft_isdigit.c \
       	ft_memset.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_isalnum.c \
       	ft_isprint.c \
	ft_strchr.c \
      	ft_strncmp.c \
	ft_toupper.c \
	ft_isalpha.c \
       	ft_memcpy.c \
      	ft_strlcat.c \
       	ft_strnstr.c \
Compiler	= gcc

CmpFlags	= -Wall -Wextra -Werror

OUTN	= $(Library).a

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

NAME	= $(OUTN)

$(NAME):
	$(Compiler) $(CmpFlags) -c $(CFILES) -I./
	ar -rc $(OUTN) $(OFILES)

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

