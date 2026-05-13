# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrice <cbrice@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:54:12 by lupayet           #+#    #+#              #
#    Updated: 2026/05/13 17:21:50 by cbrice           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = cub3D
BIN_DIR = bin
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lm

RM = rm -f
LIBFT_DIR = ./libft
MAP ?= maps/valide/test.cub

# ── Détection OS ─────────────────────────────────────────────────
OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	MLX_DIR = ./mlx_mac
	MLX_LIB = $(MLX_DIR)/libmlx.a
	INC = -I$(MLX_DIR) -I./inc -I$(LIBFT_DIR)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = ./mlx
	MLX_LIB = $(MLX_DIR)/libmlx.a
	INC = -I/opt/X11/include -I$(MLX_DIR) -I./inc -I$(LIBFT_DIR)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
endif

LIBFT = $(LIBFT_DIR)/libft.a

SRC = ./src/main.c ./src/check_map_borders.c\
	  ./src/check_map.c ./src/exit.c ./src/init_cam.c ./src/init_game.c ./src/init_map.c\
	  ./src/parse_rgb.c ./src/parsing_identifiers.c\
	  ./src/parsing_map.c ./src/read_map.c \
	  ./src/init.c ./src/close.c ./src/color.c ./src/minimap.c ./src/input.c ./src/pixel.c ./src/render.c \
	  ./src/texture.c ./src/raycast.c ./src/draw_line.c ./src/minimap_util.c ./src/draw_square.c

all: $(BIN_DIR)/$(NAME) cub

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

cub:
	@printf '#!/bin/bash\nif [[ "$$1" != *.cub ]]; then\n    printf "Error\\nFile must have .cub extension\\n"\n    exit 1\nfi\nMAP=$$(find maps/ -name "$$1" 2>/dev/null | head -1)\nif [ -z "$$MAP" ]; then\n    printf "Error\\n'\''%%s'\'' not found in maps/\\n" "$$1"\n    exit 1\nfi\n./$(BIN_DIR)/$(NAME) "$$MAP"\n' > cub
	@chmod +x cub
	@echo "> Script ./cub created"

$(MLX_LIB):
	@echo "\nCOMPILING MLX..."
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "ERROR: $(MLX_DIR) not found!"; \
		echo "Sur Mac: git clone https://github.com/42Paris/minilibx-linux mlx_mac"; \
		exit 1; \
	fi
	@if [ -f $(MLX_DIR)/configure ] && [ ! -f $(MLX_DIR)/Makefile ]; then \
		cd $(MLX_DIR) && ./configure 1>/dev/null; \
	fi
	@make -C $(MLX_DIR) 1>/dev/null
	@echo "> MLX CREATED"

$(LIBFT):
	@echo "\nCOMPILING LIBFT..."
	@make re -C $(LIBFT_DIR) 1>/dev/null
	@echo "> LIBFT CREATED"

$(BIN_DIR)/$(NAME): $(BIN_DIR) $(MLX_LIB) $(LIBFT) $(SRC)
	@echo "\nCOMPILING $(NAME)..."
	@$(CC) $(SRC) $(CFLAGS) $(INC) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(BIN_DIR)/$(NAME)
	@echo "> $(NAME) READY"

run: all
	./$(BIN_DIR)/$(NAME) $(MAP)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(BIN_DIR)/$(NAME) $(MAP)

clean:
	@if [ -f $(MLX_DIR)/Makefile ]; then make clean -C $(MLX_DIR) 1>/dev/null 2>/dev/null; fi
	@if [ -f $(LIBFT_DIR)/Makefile ]; then make clean -C $(LIBFT_DIR) 1>/dev/null; fi
	@echo "> OBJECTS CLEANED"

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(RM) $(LIBFT)
	@$(RM) cub
	@$(RM) vgcore.*
	@echo "> ALL CLEANED"

re: fclean all
dev: re
	@make clean 1>/dev/null

.PHONY: all clean fclean re run val dev cub
