CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = libftgnl.a
LIBFT = libft.a
.c.o:	${LIBFT}
		${CC} ${CFLAGS} -c -I ./libft $< -o $(<:.c=.o)
all:	${NAME}
${LIBFT}:
			$(MAKE) -C ./libft
${NAME}:	${OBJS} ${LIBFT}
			cp ./libft/libft.a ./${NAME}
			ar rc ${NAME} ${OBJS}
clean:
		rm -f ${OBJS}
		${MAKE} -C ./libft clean
fclean: clean
		rm -f ${NAME}
		${MAKE} -C ./libft fclean
re:		fclean ${NAME}
.PHONY:	all clean fclean re
