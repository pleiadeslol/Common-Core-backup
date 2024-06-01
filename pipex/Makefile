# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 02:12:42 by rzarhoun          #+#    #+#              #
#    Updated: 2024/05/27 00:55:06 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	pipex.c \
		exec_cmd.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		parsing/errors.c \
		parsing/check_path.c \
		parsing/home_env.c \
		parsing/set_args.c \
		utils/utils1.c \
		utils/utils2.c 


OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_eprintf
	$(CC) $(CFLAGS) -Lft_eprintf -lfteprintf -o $(NAME) $(OBJS)

clean:
	make clean -C ft_eprintf
	rm -f $(OBJS)

fclean: clean
	make fclean -C ft_eprintf
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re