NAME					= cub3D
LIBFT					= libft.a
CC						= gcc
CFLAGS 					= -Wall -Wextra -Werror
MLX 					= -lmlx -framework OpenGL -framework Appkit
INCLUDES_PATH			= ./includes/
LIBFT_PATH				= ./includes/libft/
GET_NEXT_LINE_PATH		= ./includes/get_next_line/
SRCS =					./includes/getnextline/get_next_line.c ./includes/getnextline/get_next_line_utils.c \
						./srcs/main.c \
						./srcs/init.c \
						./srcs/map_parsing.c \
						./srcs/ray.c \
						./srcs/textures.c \
						./srcs/utils.c \
						./srcs/move.c \
						# ./srcs/draw_sprite.c

INCS =		-I ${INCLUDES_PATH} -I ${LIBFT}

OBJS =		${SRCS:.c=.o}

.c.o:		${LIBFT}
			${CC} ${CFLAGS} -c -I $< -o $(<:.c=.o)

all:		${NAME}

${LIBFT}:
			$(MAKE) -C ${LIBFT_PATH}

${NAME}:	${OBJS}
			make -C ${LIBFT_PATH}
			$(CC) $(CFLAGS) ${INCS} -o $(NAME) $(OBJS)

clean:
		rm -f ${OBJS}
		${MAKE} -C .${LIBFT_PATH} clean

fclean: clean
		rm -f ${NAME}
		${MAKE} -C ${LIBFT_PATH} fclean

re:		fclean ${NAME}

.PHONY:	all clean fclean re