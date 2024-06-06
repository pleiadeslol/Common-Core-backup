# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 02:12:42 by rzarhoun          #+#    #+#              #
#    Updated: 2024/06/05 16:53:26 by rzarhoun         ###   ########.fr        #
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
		utils/utils2.c \
		ft_eprintf/ft_eprintf.c \
		ft_eprintf/ft_eprint_ptr.c \
		ft_eprintf/ft_eputchar.c \
		ft_eprintf/ft_eputhex.c \
		ft_eprintf/ft_eputnbr.c \
		ft_eprintf/ft_eputnbr_u.c \
		ft_eprintf/ft_eputstr.c \
		ft_eprintf/ft_strchr.c 

SRCS_BONUS =	bonus/pipex.c \
				bonus/exec_cmd.c \
				bonus/get_next_line/get_next_line.c \
				bonus/get_next_line/get_next_line_utils.c \
				bonus/parsing/errors.c \
				bonus/parsing/check_path.c \
				bonus/parsing/home_env.c \
				bonus/parsing/set_args.c \
				bonus/utils/utils1.c \
				bonus/utils/utils2.c \
				bonus/utils/utils3.c \
				bonus/here_doc/here_doc.c \
				bonus/ft_eprintf/ft_eprintf.c \
				bonus/ft_eprintf/ft_eprint_ptr.c \
				bonus/ft_eprintf/ft_eputchar.c \
				bonus/ft_eprintf/ft_eputhex.c \
				bonus/ft_eprintf/ft_eputnbr.c \
				bonus/ft_eprintf/ft_eputnbr_u.c \
				bonus/ft_eprintf/ft_eputstr.c \
				bonus/ft_eprintf/ft_strchr.c 


OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
BONUS = рipex
 
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

.SECONDARY: $(OBJS) $(OBJS_BONUS)
.PHONY: all clean fclean re