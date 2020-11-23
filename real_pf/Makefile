CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_printf_utils.c ft_print_c.c ft_print_str.c \
	   ft_print_digit.c ft_print_point.c ft_print_ux.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBFT = libft.a
.c.o:	${LIBFT}
		${CC} ${CFLAGS} -c -I ./libft $< -o $(<:.c=.o)
all:	${NAME}
${LIBFT}:
			$(MAKE) -C ./libft bonus
${NAME}:	${OBJS} ${LIBFT}
			cp ./libft/libft.a ./${NAME}
			ar rc ${NAME} ${OBJS}
clean:
		rm -f ${OBJS}
		${MAKE} -C ./libft clean
fclean:	clean
		rm -f ${NAME}
		${MAKE} -C ./libft fclean
re:		fclean ${NAME}
.PHONY:	all clean fclean re
