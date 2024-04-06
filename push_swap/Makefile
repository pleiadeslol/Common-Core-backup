# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 01:20:51 by rzarhoun          #+#    #+#              #
#    Updated: 2024/04/05 23:38:07 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c \
		sorting.c \
		actions/push.c \
		actions/reverse.c \
		actions/rotate.c \
		actions/swap.c \
		algo/check_sorted.c \
		algo/sort_five.c \
		algo/sort_four.c \
		algo/sort_three.c \
		algo/big_sort.c \
		parsing/handle_errors.c \
		parsing/init_stack.c \
		utils/utils1.c \
		utils/utils2.c \
		utils/utils3.c \
		utils/utils4.c \
		utils/utils5.c

SRCS_BONUS = checker.c \
		sorting.c \
		actions/push.c \
		actions/reverse.c \
		actions/rotate.c \
		actions/swap.c \
		algo/check_sorted.c \
		algo/sort_five.c \
		algo/sort_four.c \
		algo/sort_three.c \
		algo/big_sort.c \
		parsing/handle_errors.c \
		parsing/init_stack.c \
		utils/utils1.c \
		utils/utils2.c \
		utils/utils3.c \
		utils/utils4.c \
		utils/utils5.c \
		utils/utils6.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
BONUS = checker

all : $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re