NAME			= cub3D
LIBFT			= libft.a
CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
MLX				= -lmlx -lm -framework OpenGL -framework Appkit
LIBFT_PATH		= ./includes/libft/
SRCS =			./includes/getnextline/get_next_line.c\
				./includes/getnextline/get_next_line_utils.c \
				./srcs/main.c \
				./srcs/init.c \
				./srcs/init2.c \
				./srcs/map_parsing.c \
				./srcs/map_parsing2.c \
				./srcs/ray.c \
				./srcs/ray2.c \
				./srcs/textures.c \
				./srcs/utils.c \
				./srcs/move.c \
				./srcs/event.c \
				./srcs/draw_sprite.c \
				./srcs/bitmap.c \
				./srcs/check.c \
				./srcs/set_screen_size.c

BONUS_SRCS =	./includes/getnextline/get_next_line.c\
				./includes/getnextline/get_next_line_utils.c \
				./srcs/main.c \
				./srcs/init_bonus.c \
				./srcs/init2.c \
				./srcs/map_parsing_bonus.c \
				./srcs/map_parsing2_bonus.c \
				./srcs/ray.c \
				./srcs/ray2_bonus.c \
				./srcs/draw_sky_floor_bonus.c \
				./srcs/textures_bonus.c \
				./srcs/utils.c \
				./srcs/move.c \
				./srcs/event.c \
				./srcs/draw_sprite.c \
				./srcs/bitmap.c \
				./srcs/check.c \
				./srcs/set_screen_size.c

OBJS =			${SRCS:.c=.o}
BONUS_OBJS =	${BONUS_SRCS:.c=.o}

$(NAME):		$(OBJS)
				@echo "\033[33m[Remove last version...]"
				@rm -rf cub3D
				@echo "\033[33m[Cub3D compilation...]"
				@$(MAKE) -C ${LIBFT_PATH}
				@echo "\033[33m[Cub3D compilation...]"
				@$(CC) $(CFLAGS) $(OBJS) -I./includes -I./usr/include $(MLX) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
				@echo "\033[33m[Done!]"

all:			$(NAME)

bonus:			fclean $(BONUS_OBJS)
				@echo "\033[33m[Remove last version...]"
				@rm -rf cub3D
				@echo "\033[33m[Cub3D compilation...]"
				@$(MAKE) -C ${LIBFT_PATH}
				@echo "\033[33m[Cub3D compilation...]"
				@$(CC) $(CFLAGS) $(BONUS_OBJS) -I./includes -I./usr/include $(MLX) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
				@echo "\033[33m[Done!]"

clean:
				rm -f $(OBJS) $(BONUS_OBJS)
				$(MAKE) -C $(LIBFT_PATH) clean

fclean: 		clean
				rm -f $(NAME)
				$(MAKE) -C $(LIBFT_PATH) fclean

re:				fclean all

.PHONY:			all clean fclean re
