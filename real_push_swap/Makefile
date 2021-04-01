SRC = instructionss.c arr_merge_sort.c \
	  free_other_inst.c instructionss2.c write_add_do.c \
	  for_norm.c

SRC_CHK = checker.c
	  
SRC_PS = push_swap.c make_instructionss.c insertion_sort.c \
		 merge_sort.c optimal_insertion.c


CC = gcc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror

NAME_CHK = checker
NAME_PS = push_swap

SRCDIR = srcs
SRCDIR_CHK = srcs_chk
OBJDIR_CHK = objs_chk
SRCDIR_PS = srcs_ps
OBJDIR_PS = objs_ps
LIBDIR = libft

SRCS_CHK = $(addprefix $(SRCDIR_CHK)/, $(SRC_CHK)) $(addprefix $(SRCDIR)/, $(SRC))
OBJS_CHK = $(addprefix $(OBJDIR_CHK)/, $(OBJ_CHK)) $(addprefix $(OBJDIR_CHK)/, $(OBJ))
SRCS_PS = $(addprefix $(SRCDIR_PS)/, $(SRC_PS)) $(addprefix $(SRCDIR)/, $(SRC))
OBJS_PS = $(addprefix $(OBJDIR_PS)/, $(OBJ_PS)) $(addprefix $(OBJDIR_PS)/, $(OBJ))

OBJ = $(SRC:.c=.o)
OBJ_CHK = $(SRC_CHK:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)

LIBS = -L $(LIBDIR) -lft
HEADER = -I includes -I $(LIBDIR)

.SUFFIXES: .c .o
all: $(NAME_CHK) $(NAME_PS)
ck: $(NAME_CHK)
ps: $(NAME_PS)

#COMPILING CHECKER
$(OBJDIR_CHK)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR_CHK)
	@$(CC) $(CFLAGS) $(HEADER) $< -c -o $@

$(OBJDIR_CHK)/%.o: $(SRCDIR_CHK)/%.c
	@mkdir -p $(OBJDIR_CHK)
	@$(CC) $(CFLAGS) $(HEADER) $< -c -o $@


$(NAME_CHK): $(OBJS_CHK)
	@make -C $(LIBDIR)
	@$(CC) $(CFLAGS) $(OBJS_CHK) $(HEADER) $(LIBS) -o $@

#COMPILING PUSH_SWAP
$(OBJDIR_PS)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR_PS)
	@$(CC) $(CFLAGS) $(HEADER) $< -c -o $@

$(OBJDIR_PS)/%.o: $(SRCDIR_PS)/%.c
	@mkdir -p $(OBJDIR_PS)
	@$(CC) $(CFLAGS) $(HEADER) $< -c -o $@

$(NAME_PS): $(OBJS_PS)
	@make -C $(LIBDIR)
	@$(CC) $(CFLAGS) $(OBJS_PS) $(HEADER) $(LIBS) -o $@


clean:
	@/bin/rm -rf $(OBJDIR_CHK)
	@/bin/rm -rf $(OBJDIR_PS)
	@make -C $(LIBDIR) clean
	@echo "[Push_swap - clean]"

fclean:
	@/bin/rm -rf $(OBJDIR_CHK)
	@/bin/rm -rf $(OBJDIR_PS)
	@/bin/rm -f $(NAME_CHK)
	@/bin/rm -f $(NAME_PS)
	@make -C $(LIBDIR) fclean
	@echo "[Push_swap - fclean]"

re: fclean all
