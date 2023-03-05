
RED		:= "\e[0;31m"
GREEN	:= "\e[0;32m"
YELLOW	:= "\e[0;33m"
BLUE	:= "\e[0;34m"
MAGENTA	:= "\e[0;35m"
CYAN	:= "\e[0;36m"
RESET	:= "\e[0m"

RAW	=	ft_atof.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_clamp.c\
		ft_dellstnode.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_islower.c\
		ft_isupper.c\
		ft_iswspace.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstadd_new.c\
		ft_lstdelnode.c\
		ft_lstnew.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memdup.c\
		ft_memmove.c\
		ft_memset.c\
		ft_min_max.c\
		ft_nbrlen.c\
		ft_pow.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putnstr.c\
		ft_putstr.c\
		ft_realloc.c\
		ft_strjoin.c\
		ft_strcat.c\
		ft_strtrim.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strndup.c\
		ft_strnew.c\
		ft_strrchr.c\
		ft_strrev.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_time_func.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line.c

NAME = libft.a
CDIR = srcs
IDIR = -I.
ODIR = objs
SRCS = $(addprefix $(CDIR)/, $(RAW))
OBJS = $(addprefix $(ODIR)/, $(RAW:.c=.o))
CFLAGS = -Wall -Wextra -Werror -MMD -O3

all: $(NAME)
	@printf ${GREEN}"\e[J> $(NAME) ready!\n"${RESET}

$(ODIR):
	@mkdir -p $(ODIR)

$(ODIR)/%.o: $(CDIR)/%.c
	@printf $(YELLOW)"\e[JCompiling $<\n\e[F"$(RESET)
	@gcc -c $< -o $@ $(CFLAGS) $(IDIR)

$(NAME): $(ODIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean: 
	@printf ${CYAN}"[INFO] Removing object files.\n"${RESET}
	@rm -rf $(ODIR)

fclean: clean
	@printf ${CYAN}"[INFO] Removing $(NAME)\n"${RESET}
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean re $(NAME)
