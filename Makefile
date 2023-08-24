# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 10:04:45 by axcallet          #+#    #+#              #
#    Updated: 2023/08/24 17:32:44 by axcallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## COLORS ##########

_END		="\033[0m"
_RED		="\033[0;31m"
_GREEN		="\033[0;32m"
_YELLOW		="\033[0;33m"
_CYAN		="\033[0;36m"

########## ARGUMENTS ##########

NAME		= cub3d
CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g3

########## SOURCES ##########

SRC_DIR		= src
OBJ_DIR		= obj
LIBX_DIR	= lib/minilibx
LIBFT_DIR	= lib/libft
INC			= -Iinclude -Iinc
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MAKE_LIBFT	= $(LIBFT_DIR)/libft.a
MAKE_LIBX	= $(LIBX_DIR)/build/libmlx42.a
LIB			= $(MAKE_LIBFT) $(MAKE_LIBX) -ldl -lglfw -pthread -lm

################## SRC ###################

SRC = src/main.c									\
	  src/collider/check_collider.c					\
	  src/hook/key_hook.c							\
	  src/hook/loop_hook.c							\
	  src/hook/key/key_action.c						\
	  src/hook/key/key_applied.c					\
	  src/hook/movement/player_movement.c			\
	  src/init/init_values.c						\
	  src/loader/texture/load_texture.c				\
	  src/loader/map/parsing/arguments.c			\
	  src/loader/map/parsing/check_file.c			\
	  src/loader/map/parsing/map.c					\
	  src/loader/map/parsing/map_utils.c			\
	  src/loader/map/parsing/parsing.c				\
	  src/loader/map/parsing/utils.c				\
	  src/loader/map/parsing/format.c				\
	  src/raycasting/fisheye/get_ray_min_dist.c		\
	  src/raycasting/check_infinite_value.c			\
	  src/raycasting/get_rey_side.c					\
	  src/raycasting/perform_dda.c					\
	  src/raycasting/raycaster.c					\
	  src/renderer/render.c							\
	  src/renderer/draw_floor.c						\
	  src/renderer/draw_ceiling.c					\
	  src/renderer/wall/draw_wall.c					\
	  src/renderer/wall/draw_wall_ling.c			\
	  src/renderer/wall/get_wall_texture.c			\
	  src/renderer/wall/get_line_gap.c				\
	  src/renderer/player/player_swing.c			\
	  src/renderer/player/crosshair.c				\
	  src/renderer/fog/wall_fog.c					\
	  src/renderer/fog/back_fog.c					\
	  src/utils/coordinates/get_cardinal_points.c	\
	  src/utils/rad_converter.c						\
	  src/utils/free/free_all.c						\
	  src/utils/img_to_struct.c						\
	  src/utils/rgba_to_hex.c						\
	  src/utils/cmp_tab.c

########## RULES ##########

all: $(NAME)

$(NAME): $(MAKE_LIBX) $(MAKE_LIBFT) $(OBJ_DIR) $(OBJ)
	@echo $(_GREEN)- Compiling src$(END)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)

$(MAKE_LIBX):
	@cmake $(LIBX_DIR) -B $(LIBX_DIR)/build > /dev/null && make -C $(LIBX_DIR)/build -j4 > /dev/null

$(MAKE_LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@echo ''
	@echo $(_RED)'                  __           __       __'
	@echo '                 /\ \        / __ \    /\ \'
	@echo '  ___    __  __  \ \ \____  /\_\L\ \   \_\ \'
	@echo ' / ___\ /\ \/\ \  \ \  __ \ \/_/_\_<_  / _  \'
	@echo '/\ \__/ \ \ \_\ \  \ \ \L\ \  /\ \L\ \/\ \L\ \'
	@echo '\ \____\ \ \____/   \ \____/  \ \____/\ \_____\'
	@echo ' \/____/  \/___/     \/___/    \/___/  \/____ /'
	@echo '               By Axel && Arty'$(END)
	@echo ''
	@mkdir -p $@
	@echo $(_CYAN)- Create obj directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	@echo $(_YELLOW)- Cleaning obj directory$(END)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(_RED)- Cleaning executable$(END)
	@echo $(_RED)- Cleaning minilibx build directory$(END)
	@rm -f $(NAME)
	@rm -rf $(LIBX_DIR)/build

re: fclean all

.PHONY: all fclean clean re
