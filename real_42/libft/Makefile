NAME	=	libft.a
SRC		=	ft_atoi.c			ft_bzero.c			ft_calloc.c		\
			ft_isalpha.c		ft_isalnum.c		ft_isdigit.c	\
			ft_memccpy.c		ft_memcpy.c			ft_isprint.c	\
			ft_memmove.c		ft_memset.c			ft_putchar_fd.c	\
			ft_putendl_fd.c		ft_putnbr_fd.c		ft_putstr_fd.c	\
			ft_split.c			ft_strchr.c			ft_strncmp.c	\
			ft_strdup.c			ft_strjoin.c		ft_strlcat.c	\
			ft_strlcpy.c		ft_strlen.c			ft_strmapi.c	\
			ft_strnstr.c		ft_strrchr.c		ft_memcmp.c		\
			ft_strtrim.c		ft_substr.c			ft_tolower.c	\
			ft_toupper.c		ft_isascii.c		ft_itoa.c		\
			ft_memchr.c
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OBJ		=	$(SRC:.c=.o)
BONUS	=	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c	\
			ft_lstlast.c		ft_lstadd_back.c	ft_lstmap.c		\
			ft_lstdelone.c		ft_lstclear.c		ft_lstiter.c
B_OBJ	=	$(BONUS:.c=.o)
RM		=	rm -rf
.c.o:
			${CC} ${CFLAGS} -I -c $< -o ${<:.c=.o}
$(NAME): 	${OBJ}
			ar rc ${NAME} ${OBJ}
all:		${NAME}
bonus:		${OBJ} ${B_OBJ}
			ar rc ${NAME} ${OBJ} ${B_OBJ}
clean:
			${RM} ${OBJ} ${B_OBJ}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
