# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 04:48:07 by rzarhoun          #+#    #+#              #
#    Updated: 2024/09/24 17:21:34 by rzarhoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	philo.c \
		init_philo.c \
		actions.c \
		monitor.c \
		philo_routine.c \
		create/create_forks.c \
		create/create_thread.c \
		parsing/parse_data.c \
		parsing/check_args.c \
		utils/utils.c \
		utils/time.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=thread
NAME = philo
 
all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re
