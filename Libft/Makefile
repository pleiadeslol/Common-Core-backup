# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:18:43 by rzarhoun          #+#    #+#              #
#    Updated: 2023/11/02 16:56:21 by rzarhoun         ###   ########.fr        #
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
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
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

