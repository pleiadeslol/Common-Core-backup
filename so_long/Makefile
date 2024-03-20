# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 22:02:54 by rzarhoun          #+#    #+#              #
#    Updated: 2024/03/19 22:12:25 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c \
		flood_fill.c \
		game/draw.c \
		game/move.c \
		gnl/gnl.c \
		gnl/gnl_utils.c \
		parsing/parsing1.c \
		parsing/parsing2.c \
		parsing/errors.c \
		utils/utils1.c \
		utils/utils2.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) -Imlx -lmlx -framework OpenGL -framework AppKit -Lft_printf -lftprintf -o $(NAME) $(OBJS)

bonus:
	make -C so_long_bonus

clean:
	make clean -C ft_printf
	make clean -C so_long_bonus
	rm -f $(OBJS)

fclean: clean
	make fclean -C ft_printf
	make fclean -C so_long_bonus
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re