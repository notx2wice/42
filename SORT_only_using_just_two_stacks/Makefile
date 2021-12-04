SRC = print_stack.c instructionss.c arr_merge_sort.c \
	  free_other_inst.c instructionss2.c write_add_do.c \
	  for_norm.c

SRC_CHK = checker.c
	  
SRC_PS = push_swap.c make_instructionss.c insertion_sort.c \
		 merge_sort.c optimal_insertion.c

SRC_RAND = rand_gen.c

CC = gcc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror

NAME_CHK = checker
NAME_PS = push_swap
NAME_RAND = rand_generators

SRCDIR = srcs
SRCDIR_CHK = srcs_chk
OBJDIR_CHK = objs_chk
SRCDIR_PS = srcs_ps
OBJDIR_PS = objs_ps
SRCDIR_RAND = srcs_rand
OBJDIR_RAND = objs_rand
LIBDIR = libft

SRCS_CHK = $(addprefix $(SRCDIR_CHK)/, $(SRC_CHK)) $(addprefix $(SRCDIR)/, $(SRC))
OBJS_CHK = $(addprefix $(OBJDIR_CHK)/, $(OBJ_CHK)) $(addprefix $(OBJDIR_CHK)/, $(OBJ))
SRCS_PS = $(addprefix $(SRCDIR_PS)/, $(SRC_PS)) $(addprefix $(SRCDIR)/, $(SRC))
OBJS_PS = $(addprefix $(OBJDIR_PS)/, $(OBJ_PS)) $(addprefix $(OBJDIR_PS)/, $(OBJ))
SRCS_RAND = $(addprefix $(SRCDIR_RAND)/, $(SRC_RAND))
OBJS_RAND = $(addprefix $(OBJDIR_RAND)/, $(OBJ_RAND))

OBJ = $(SRC:.c=.o)
OBJ_CHK = $(SRC_CHK:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)
OBJ_RAND = $(SRC_RAND:.c=.o)

LIBS = -L $(LIBDIR) -lft
HEADER = -I includes -I $(LIBDIR)

.SUFFIXES: .c .o
all: $(NAME_CHK) $(NAME_PS) $(NAME_RAND)
ck: $(NAME_CHK)
ps: $(NAME_PS)
rd: $(NAME_RAND)

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

#COMPILING RAND_GENERATOR
$(OBJDIR_RAND)/%.o: $(SRCDIR_RAND)/%.c
	@mkdir -p $(OBJDIR_RAND)
	@$(CC) $(CFLAGS) $(HEADER) $< -c -o $@

$(NAME_RAND): $(OBJS_RAND)
	@$(CC) $(CFLAGS) $(OBJS_RAND) $(HEADER) $(LIBS) -o $@

clean:
	@/bin/rm -rf $(OBJDIR_CHK)
	@/bin/rm -rf $(OBJDIR_PS)
	@/bin/rm -rf $(OBJDIR_RAND)
	@make -C $(LIBDIR) clean
	@echo "[Push_swap - clean]"

fclean:
	@/bin/rm -rf $(OBJDIR_CHK)
	@/bin/rm -rf $(OBJDIR_PS)
	@/bin/rm -rf $(OBJDIR_RAND)
	@/bin/rm -f $(NAME_CHK)
	@/bin/rm -f $(NAME_PS)
	@/bin/rm -f $(NAME_RAND)
	@make -C $(LIBDIR) fclean
	@echo "[Push_swap - fclean]"

re: fclean all
