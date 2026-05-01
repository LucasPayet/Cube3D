# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:54:12 by lupayet           #+#    #+#              #
#    Updated: 2026/04/27 05:52:52 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

NAME = cube3D

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g

RM = rm -f

LIBFT_P = ./libft/
MLX_P = ./mlx/

LIBFT = $(LIBFT_P)libft.a
MLX = $(MLX_P)libmlx_Linux.a

SRC_D = ./src/
INC = ./inc/
OBJ_D = ./obj/

SRC	= main.c init.c close.c color.c minimap.c input.c pixel.c render.c raycast.c
HEADER = cube.h s_cube.h

OBJ	= $(addprefix $(OBJ_D), $(SRC:.c=.o))
DEPS = $(addprefix $(INC), $(HEADER))

$(OBJ_D)%.o: $(SRC_D)%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INC) -I$(LIBFT_P) -I$(MLX_P) -I./usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(OBJ_D):
	@mkdir -p $(OBJ_D)

$(MLX):
	@echo "\nCOMPILING MLX..."
	@make -C $(MLX_P)
	@echo "> MLX CREATED"

$(LIBFT):
	@echo "\nCOMPILING LIBFT..."
	@make -C $(LIBFT_P) 1>/dev/null
	@echo "> LIBFT CREATED"

$(NAME): $(MLX) $(LIBFT) $(OBJ_D) $(OBJ)
	@echo "\nCOMPILING cube3D..."
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L./mlx/ -lmlx -lXext -lX11 -lm $(LIBFT_P)libft.a -o $(NAME)
	@echo "> cube3D READY"

clean:
	@make clean -C $(MLX_P) 1>/dev/null 2>/dev/null
	@make clean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(NAME)


bonus: $(BONUS)

re:fclean all

rebonus: fclean bonus

dev: re
	@make clean 1>/dev/null

devbonus: rebonus
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
