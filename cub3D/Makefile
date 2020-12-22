NAME					= cub3D
LIBFT					= libft.a
CC						= gcc
CFLAGS 					= -Wall -Wextra -Werror
LXFLAGS					= ./minilibxopengl
MLX 					= -lmlx -framework OpenGL -framework Appkit
INCLUDES_PATH			= ./includes/
LIBFT_PATH				= ./includes/libft/
SRCS =					./includes/getnextline/get_next_line.c\
						./includes/getnextline/get_next_line_utils.c \
						./srcs/main.c \
						./srcs/init.c \
						./srcs/map_parsing.c \
						./srcs/ray.c \
						./srcs/textures.c \
						./srcs/utils.c \
						./srcs/move.c \
						# ./srcs/draw_sprite.c

OBJS =		${SRCS:%.c=%.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBFT_PATH}
			$(CC) $(CFLAGS) -o $(NAME) -I $(LIBFT_PATH)$(LIBFT)  \
			-L  $(LXFLAGS) $(MLX) $(OBJS)
clean:
		rm -f ${OBJS}
		${MAKE} -C .${LIBFT_PATH} clean

fclean: clean
		rm -f ${NAME}
		${MAKE} -C ${LIBFT_PATH} fclean

re:		fclean ${NAME}

.PHONY:	all clean fclean re