# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 14:06:05 by nlence-l          #+#    #+#              #
#    Updated: 2025/01/29 15:06:26 by jlecorne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY 	= \033[90m
GREEN   = \033[32m
RED		= \033[31m
MAGENTA = \033[35m
YELLOW  = \033[33m
BLUE	= \033[34m
BOLD	= \033[1m
RESET   = \033[0m

NAME		= cub3D

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-ggdb3 #-> Valgrind
SRCDIR		= srcs
SRC			= $(shell find $(SRCDIR) -name '*.c')
# SRC 		= $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c) $(wildcard $(SRCDIR)/*/*/*.c)
OBJDIR		= .obj
OBJ 		= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
HEADER		= -I include -I ./libft/include -I -L/opt/homebrew/opt/glfw/include #glwf path depends on OS
LIBS 		= -L./MLX42/build -lmlx42 ./libft/libft.a -ldl -L/opt/homebrew/opt/glfw/lib -lglfw -pthread -lm
LIBFT 		= libft/libft.a
MLX42_LIB 	= MLX42/build/libmlx42.a

all: $(NAME)

$(LIBFT)	:
	$(MAKE) -sC libft

$(MLX42_LIB):
	@printf "$(GRAY) - MLX42$(RESET)\t"
	@cmake -S MLX42 -B MLX42/build
	@make -C MLX42/build -j4
	@printf "$(GREEN)[OK]$(RESET)\n"

# Linking des objets et libs
$(NAME): $(MLX42_LIB) $(LIBFT) $(OBJ)
	@printf "$(GRAY) - $(NAME)$(RESET)\t"
	@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(LIBS) -o $(NAME)
	@printf "$(GREEN)[OK]$(RESET)\n"

# Compilation des sources et gestion de fichiers d'objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Suppression objets libft
clib:
	@$(MAKE) clean -sC libft

# Suppression programme libft
fclib:
	@$(MAKE) fclean -sC libft

# Suppression objets
clean: clib
	@if [ -d "$(OBJDIR)" ]; then \
		printf "$(GRAY) - $(NAME)$(RESET)\t"; \
		rm -rf $(OBJDIR); \
		printf "$(BLUE)[OBJECTS REMOVED]$(RESET)\n"; \
	else \
		printf "$(GRAY) - $(NAME)$(RESET)\t$(YELLOW)[NO OBJECTS FOUND]$(RESET)\n"; \
	fi

# Suppression programme
fclean: clean fclib
	@if [ -e "$(NAME)" ]; then \
		printf "$(GRAY) - $(NAME)$(RESET)\t"; \
		rm -f $(NAME); \
		printf "$(BLUE)[PROGRAM REMOVED]$(RESET)\n"; \
	else \
		printf "$(GRAY) - $(NAME)$(RESET)\t$(YELLOW)[NO FILE FOUND]$(RESET)\n"; \
	fi

re: fclean all

# Linking debug
debug: $(LIBFT) $(OBJ)
	@printf "$(GRAY) - $(NAME)$(RESET)\t"
	@$(CC) -g3 $(CFLAGS) $(HEADER) $(OBJ) $(LIBS) -o $(NAME) -fsanitize=address
	@printf "$(BOLD)$(MAGENTA)[DEBUG]$(RESET)\n"

.PHONY: all, clib, fclib, clean, fclean, re, debug