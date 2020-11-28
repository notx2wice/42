NAME = libft.a
CC = gcc
AFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_itoa.c ft_strdup.c  ft_strlen.c ft_isdigit.c ft_strjoin.c
OBJECTS = $(SRCS:.c=.o)
all : $(NAME)
clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
$(NAME) : $(OBJECTS)
	ar $(AFLAGS) $(NAME) $(OBJECTS)
.PHONY : all clean fclean re%
