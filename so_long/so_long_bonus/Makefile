# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 22:02:54 by rzarhoun          #+#    #+#              #
#    Updated: 2024/03/19 22:17:28 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main_bonus.c \
		flood_fill_bonus.c \
		game/draw1_bonus.c \
		game/draw2_bonus.c \
		game/move_bonus.c \
		game/sprites_bonus.c \
		gnl/gnl.c \
		gnl/gnl_utils.c \
		parsing/parsing1_bonus.c \
		parsing/parsing2_bonus.c \
		parsing/parsing3_bonus.c \
		parsing/errors_bonus.c \
		utils/utils1_bonus.c \
		utils/utils2_bonus.c \
		utils/utils3_bonus.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long_bonus

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) -Imlx -lmlx -framework OpenGL -framework AppKit -Lft_printf -lftprintf -o $(NAME) $(OBJS)

clean:
	make clean -C ft_printf
	rm -f $(OBJS)

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re