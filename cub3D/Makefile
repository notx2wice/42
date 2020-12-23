NAME					= cub3D
LIBFT					= libft.a
CC						= gcc
CFLAGS 					= -Wall -Wextra -Werror

MINILIBX_OPENGL			= ./includes/minilibx_opengl/
MINILIBX_MMS			= ./includes/minilibx_mms/
LIBFT_PATH				= ./includes/libft/

INCLIB_OPENGL			= -L${MINILIBX_OPENGL} -lmlx -framework OpenGL -framework Appkit
INCLIB_MMS				= -L${MINILIBX_MMS} -lmlx -framewor Cocoa -framework Metal -framework MetalKit -framwork QuartzCore

INCS					= -I./includes/ -I${LIBFT_PATH} -I${MINILIBX_MMS}

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

$(NAME):	$(OBJS)
			@echo "\033[33m[Remove last version...]"
			@rm -rf cub3D
			@echo "\033[33m[Cub3D compilation...]"
			@make -C ${LIBFT_PATH}
			@echo "\033[33m[Cub3D compilation...]"
			@make -C ${MINILIBX_OPENGL}
			@$(CC) $(CFLAGS) $(OBJS) $(INCS) $(INCLIB_OPENGL) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
			@echo "\033[33m[Done!]"

all:		$(NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_PATH) clean
		$(MAKE) -C $(MINILIBX_OPENGL) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean

re:		fclean all

.PHONY:	all clean fclean re
