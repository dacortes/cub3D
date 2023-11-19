# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:31:31 by codespace         #+#    #+#              #
#    Updated: 2023/11/19 10:21:06 by dacortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                               VARIABLES                                      #
################################################################################

NAME = cub3D
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -O3 -g

################################################################################
#  Bar                                                                         #
################################################################################

CURRENT_FILE = 0
PROGRESS_BAR :=

################################################################################
#                               SOURCES                                        #
################################################################################

SRC = main.c
OS := $(shell uname)

#L_MLX = ./miniLibX/libmlx.a
#L_FRAME = -framework OpenGL -framework AppKit

LIBFT = ./lib/libft/
MINIL = ./lib/minilibx_linux/
L_SRC = ./src
L_LIB = ./lib/libft/libft.a
L_MLX = ./lib/minilibx_linux/libmlx.a
L_FRAME = -lXext -lX11 -lm -lz  #-framework OpenGL -framework AppKit
INC			=	-I ./inc/\
				-I ./lib/libft/\
				-I ./lib/minilibx_linux/

################################################################################
#                               DIRECTORIES                                    #
################################################################################

D_OBJ = $(L_SRC)/obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

################################################################################
#                               BOLD COLORS                                    #
################################################################################

E = \033[m
R = \033[31m
G = \033[32m
Y = \033[33m
B = \033[34m
P = \033[35m
C = \033[36m

################################################################################
#  FONT                                                                        #
################################################################################

ligth = \033[1m
dark = \033[2m
italic = \033[3m

################################################################################
#                               MAKE RULES                                     #
################################################################################

all: dir $(NAME)
-include $(DEP)
dir:
	@echo dir start
	mkdir -p $(D_OBJ)
	mkdir -p $(D_OBJ)/sets
	mkdir -p $(D_OBJ)/menu
	@echo dir end

libs:
	make -C $(LIBFT) --no-print-directory
ifeq ($(OS), Linux)
	@echo "Compiling Linux version"; echo "Calling minilibx $!";
	#Redirigir-lo a /dev/null implica que se ejecute en el background y que se acabe con la rule antes de que este compilada la minilibx.
	#Esto provoca un error en los archivos que dependen de ella. Tamiben altera el estado de la consola, creando el efecto de que no sale el prompt al final de la compilacion.
	#make -C $(MINIL) --no-print-directory &> /dev/null ; echo "Called minilibx $!";
	make -C $(MINIL) --no-print-directory ; echo "Called minilibx $!";
	@echo "Compiled Linux version";
else
	@echo "No soy linux :( $(OS)";
endif
	@echo "Compiled Linux version";

$(D_OBJ)/%.o:$(L_SRC)/%.c
	$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)
	$(eval CURRENT_FILE := $(shell echo $$(($(CURRENT_FILE) + 1)))) \
	$(eval PROGRESS_BAR := $(shell awk "BEGIN { printf \"%.0f\", $(CURRENT_FILE)*100/$(TOTAL_FILES) }")) \
	printf "\r$B$(ligth)⏳Compiling $(NAME):$E $(ligth)%-30s [$(CURRENT_FILE)/$(TOTAL_FILES)] [%-50s] %3d%%\033[K" \
	"$<..." "$(shell printf '$(G)█%.0s$(E)$(ligth)' {1..$(shell echo "$(PROGRESS_BAR)/2" | bc)})" $(PROGRESS_BAR)
	
	@if [ $(PROGRESS_BAR) = 100 ]; then \
		echo "$(B) All done$(E)"; \
	fi
$(NAME): $(OBJ) libs
	$(CC) $(FLAGS) $(OBJ) $(L_LIB) $(L_MLX) $(L_FRAME) -o $(NAME) $(INC)

################################################################################
#                               CLEAN                                          #
################################################################################

.PHONY: all clean fclean re
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT) --no-print-directory
	echo "✅ ==== $(P)$(ligth)fractol executable files and name cleaned!$(E) ==== ✅\n"
clean:
	$(RM) $(D_OBJ)
	make clean -C $(LIBFT) --no-print-directory
	make clean -C $(MINIL) --no-print-directory
	echo "✅ ==== $(P)$(ligth)fractol object files cleaned!$(E) ==== ✅"
re: fclean all
TOTAL_FILES := $(words $(SRC))
.SILENT:
