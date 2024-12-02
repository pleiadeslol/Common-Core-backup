SRCS = src/parsing/lexer.c src/utils/helper1.c src/utils/helper2.c src/utils/helper3.c src/utils/helper4.c src/utils/helper5.c src/parsing.c \
		src/utils/helper6.c src/utils/helper7.c src/utils/helper8.c src/utils/helper9.c src/utils/helper10.c src/parsing/env_class.c src/utils/helper11.c \
		src/utils/helper12.c src/utils/helper13.c src/utils/helper14.c src/utils/helper15.c src/utils/helper16.c src/utils/helper17.c \
		src/utils/helper18.c src/utils/helper19.c src/utils/helper20.c src/utils/helper21.c src/utils/helper22.c src/utils/helper23.c src/utils/helper24.c \
		src/builtins/echo.c src/builtins/cd.c \
		src/exec/find_env.c src/builtins/pwd.c src/builtins/env.c \
		src/builtins/exit.c src/exec/path.c src/exec/exec.c src/exec/signals.c \
		src/builtins/export.c src/builtins/unset.c src/exec/redirections.c src/exec/sigquit.c\
		src/exec/here_doc.c src/get_next_line/get_next_line.c src/exec/putfd.c \
		src/exec/init_exec.c src/exec/cleanup.c src/exec/update_env.c src/exec/check_path.c \
		src/exec/exec_builtins.c src/exec/exec_cmd.c src/exec/set_status.c \
		src/builtins/exit_helper.c src/exec/handle_path.c

HEAD = -I includes

Objects = ${SRCS:.c=.o}

NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3 $(HEAD)

Includes = includes/lexer.h

all : ${NAME}

${NAME} : ${Objects} 
	cc ${CFLAGS} ${Objects} -lreadline -o ${NAME}

clean :
	rm -f ${Objects}
fclean : clean
	rm -f ${NAME}
re : fclean all

.SECONDARY: $(Objects)
.PHONY: all clean fclean re