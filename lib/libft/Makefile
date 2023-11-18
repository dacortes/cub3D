# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 10:25:51 by dacortes          #+#    #+#              #
#    Updated: 2023/09/12 16:26:40 by dacortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== VARIABLES ================================== #

NAME	=	libft.a
CC		=	gcc
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar -rcs
CURRENT_FILE = 0
PROGRESS_BAR :=

# =========================== SOURCES ======================================== #

SRCS	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_memchr.c\
				ft_strchr.c ft_memcmp.c ft_strrchr.c ft_strncmp.c ft_strnstr.c\
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_printf.c ft_type_cs.c ft_type_idupxX.c\
				get_next_line_bonus.c get_next_line_utils_bonus.c\
				get_next_line.c get_next_line_utils.c\
				ft_addend_char.c ft_addstart_char.c ft_strchrpos.c\
				ft_double_ptrlen.c ft_close_del.c\
				fd_type_cs.c fd_type_idup.c fd_type_xX.c fd_printf.c\
				ft_difcpy.c ft_cutdel.c ft_strcpy.c ft_strncpy.c
				
BONUS 	= 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

# =========================== DIRECTORIES ==================================== #

D_OBJ = obj
#.o
OBJ = $(addprefix $(D_OBJ)/, $(SRCS:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRCS:.c=.d))
#Bonus .o
B_OBJ = $(addprefix $(D_OBJ)/, $(BONUS:.c=.o))
B_DEP = $(addprefix $(D_OBJ)/, $(BONUS:.c=.d))

# =========================== BOLD COLORS ==================================== #

E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
P = \033[35m
C = \033[36m
#Font
ligth = \033[1m
dark = \033[2m
italic = \033[3m

# ========================== MAKE RULES ===================================== #
all:	dir $(NAME)
-include $(DEP)
-include $(B_DEP)

dir: 
	-mkdir $(D_OBJ)

#Compilation with loading bar
$(D_OBJ)/%.o: %.c
	$(CC) -MMD $(FLAGS) -c $< -o $@
	$(eval CURRENT_FILE := $(shell echo $$(($(CURRENT_FILE) + 1)))) \
	$(eval PROGRESS_BAR := $(shell awk "BEGIN { printf \"%.0f\", $(CURRENT_FILE)*100/$(TOTAL_FILES) }")) \
	printf "\r$B$(ligth)⏳Compiling libft:$E $(ligth)%-30s [$(CURRENT_FILE)/$(TOTAL_FILES)] [%-50s] %3d%%\033[K" \
	"$<..." "$(shell printf '$(G)█%.0s$(E)$(ligth)' {1..$(shell echo "$(PROGRESS_BAR)/2" | bc)})" $(PROGRESS_BAR)
	
	@if [ $(PROGRESS_BAR) = 100 ]; then \
		echo "$(B) All done$(E)"; \
	fi
$(NAME):	${OBJ}
	$(LIBC) $(NAME) $(OBJ)
	touch $(NAME)
	echo "\n\n✅ ==== $(B)$(ligth)Project libft compiled!$(E) ==== ✅"
bonus:	dir ${B_OBJ} $(NAME)
	if [ -f bonus ]; then\
		echo "$(B)$(ligth)make:$(E)$(ligth) 'bonus' is up to date.$(E)";\
	else\
		$(LIBC) $(NAME) $(OBJ) $(B_OBJ);\
		touch bonus;\
		echo "$B$(ligth)⏳Compiling libft:$E";\
	fi
# ========================== CLEAN   ===================================== #
.PHONY: all clean fclean re bonus
clean:
	$(RM) $(D_OBJ) bonus
	echo "✅ ==== $(P)$(ligth)Libft object files cleaned!$(E) ==== ✅"
fclean: clean
	$(RM) $(NAME)
	echo "✅ ==== $(P)$(ligth)Libft executable files and name cleaned!$(E) ==== ✅\n"
re: fclean all
TOTAL_FILES := $(words $(SRCS))
.SILENT: