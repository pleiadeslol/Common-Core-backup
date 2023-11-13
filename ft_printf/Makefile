#**************************************************************************** #
# #
# :: : :: :: :: ::#
#Makefile : + : : + : : + : #
#+ : + + : + + : + #
#By : rzarhoun < rzarhoun @student .42.fr> + # + + : ++# + #
#+ #+ #+ #+ #+ #+ + #+ #
#Created : 2023 / 11 / 13 15 : 08 : 19 by rzarhoun # + # # + # #
#Updated : 2023 / 11 / 13 18 : 49 : 43 by rzarhoun## # ########.fr #
# #
#**************************************************************************** #

SRCS = ft_printf.c

			OBJS = $(SRCS
					:.c =.o) CC = cc CFLAGS = -Wall - Werror
						- Wextra NAME = libftprintf.a

																					all : $(NAME)

																							$(NAME)
	: $(OBJS) ar rcs $(NAME) $(OBJS) %.o : %.c $(CC) $(CFLAGS) -
	c $ *.c -
	o $ *
			.o

				clean : rm -
	f *
			.o

				fclean : clean rm -
	f $(NAME)

		re : fclean all

					.PHONY : all clean fclean re