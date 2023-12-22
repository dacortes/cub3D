# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:31:31 by codespace         #+#    #+#              #
#    Updated: 2023/12/21 18:29:17 by dacortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                               VARIABLES                                      #
################################################################################

NAME = cub3D
CC = gcc
RM = rm -rf
LIBC = ar -rcs
OS := $(shell uname -s)
FLAGS = -Wall -Wextra -Werror -O3 -g #-fsanitize=address

################################################################################
#  Bar                                                                         #
################################################################################

CURRENT_FILE = 0
PROGRESS_BAR :=

################################################################################
#                               SOURCES                                        #
################################################################################

ifeq ($(OS), Linux)
	MINIL = ./lib/minilibx_linux/
	L_MLX = ./lib/minilibx_linux/libmlx.a
	L_FRAME = -lXext -lX11 -lm -lz
	DEF_LIB = -D INC_LINUX=1
	INC			=	-I ./inc/\
				-I ./lib/libft/\
				-I ./lib/minilibx_linux/	
else
	MINIL = ./lib/minilibx_mac/
	L_MLX = ./lib/minilibx_mac/libmlx.a
	L_FRAME = -framework OpenGL -framework AppKit
	DEF_LIB = -D INC_MAC=1
	INC			=	-I ./inc/\
				-I ./lib/libft/\
				-I ./lib/minilibx_mac/
endif

SRC = init/init.c\
	parsing/check_access.c parsing/getcolor.c parsing/getdimensions.c\
	parsing/getmap.c parsing/getpath.c parsing/parse.c parsing/utils.c\
	parsing/utils2.c\
	minimap/bob_ross.c minimap/events.c minimap/loop.c minimap/minimap.c\
	minimap/points.c minimap/ray_calculator.c minimap/utils.c\
	main.c utils.c
LIBFT = ./lib/libft/
L_SRC = ./src
L_LIB = ./lib/libft/libft.a

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
	mkdir -p $(D_OBJ)
	mkdir -p $(D_OBJ)/init	
	mkdir -p $(D_OBJ)/parsing
	mkdir -p $(D_OBJ)/minimap
libs:
	make -C $(LIBFT) --no-print-directory
	make -C $(MINIL) --no-print-directory

$(D_OBJ)/%.o:$(L_SRC)/%.c Makefile
	$(CC) -MMD $(DEF_LIB) $(FLAGS) -c $< -o $@ $(INC)
	$(eval CURRENT_FILE := $(shell echo $$(($(CURRENT_FILE) + 1)))) \
	$(eval PROGRESS_BAR := $(shell awk "BEGIN { printf \"%.0f\", $(CURRENT_FILE)*100/$(TOTAL_FILES) }")) \
	printf "\r$B$(ligth)⏳Compiling $(NAME):$E $(ligth)%-30s [$(CURRENT_FILE)/$(TOTAL_FILES)] [%-50s] %3d%%\033[K" \
	"$<..." "$(shell printf '$(G)█%.0s$(E)$(ligth)' {1..$(shell echo "$(PROGRESS_BAR)/2" | bc)})" $(PROGRESS_BAR)
	
	@if [ $(PROGRESS_BAR) = 100 ]; then \
		echo "$(B) All done$(E)"; \
	fi
$(NAME): $(OBJ) libs
	$(CC) $(DEF_LIB) $(FLAGS) $(OBJ) $(L_LIB) $(L_MLX) $(L_FRAME) -o $(NAME) $(INC)

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
