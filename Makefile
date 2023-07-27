_END="\033[0m"
_RED="\033[0;31m"
_GREEN="\033[0;32m"
_YELLOW="\033[0;33m"
_CYAN="\033[0;36m"

SRC_DIR = src
OBJ_DIR = obj
LIBX_DIR = lib/minilibx
LIBFT_DIR	= lib/libft
CC = clang
CFLAGS = -Wall -Werror -Wextra -g3
INC = -Iinclude -Iinc
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MAKE_LIBFT = $(LIBFT_DIR)/libft.a
MAKE_LIBX = $(LIBX_DIR)/build/libmlx42.a
LIB =  $(MAKE_LIBFT) $(MAKE_LIBX) -ldl -lglfw -pthread -lm

################## SRC ###################
SRC = src/main.c									\
	  src/collider/check_collider.c					\
	  src/hook/key_hook.c							\
	  src/hook/loop_hook.c							\
	  src/hook/key/key_action.c						\
	  src/hook/key/key_applied.c					\
	  src/hook/mouse/mouse_hook.c					\
	  src/hook/movement/player_movement.c			\
	  src/hook/movement/player_view.c				\
	  src/init/init_values.c						\
	  src/loader/texture/load_texture.c				\
	  src/loader/map/parsing/arguments.c			\
	  src/loader/map/parsing/check_file.c			\
	  src/loader/map/parsing/format.c				\
	  src/loader/map/parsing/map.c					\
	  src/loader/map/parsing/parsing.c				\
	  src/loader/map/parsing/utils.c				\
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
	  src/renderer/weapon/mouv_weapon.c				\
	  src/renderer/player/player_swing.c			\
	  src/renderer/player/crosshair.c				\
	  src/renderer/minimap/minimap.c				\
	  src/utils/coordinates/get_cardinal_points.c	\
	  src/utils/rad_converter.c						\
	  src/utils/free/free_all.c						\
	  src/utils/free/free_ray_array.c				\
	  src/utils/img_to_struct.c						\
	  src/utils/rgba_to_hex.c						\
	  src/utils/cmp_tab.c
##########################################
NAME = cub3d

all: $(NAME)

$(NAME): $(MAKE_LIBX) $(MAKE_LIBFT) $(OBJ_DIR) $(OBJ)
	@echo $(_GREEN)Compiling $(OBJ)...$(END)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)
$(MAKE_LIBX):
	@cmake $(LIBX_DIR) -B $(LIBX_DIR)/build && make -C $(LIBX_DIR)/build -j4

$(MAKE_LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	@echo $(_CYAN)Compiling $<...$(END)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	@echo $(_YELLOW)Cleaning $(OBJ)...$(END)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(_RED)Cleaning $(NAME)...$(END)
	@rm -f $(NAME)
	@rm -rf $(LIBX_DIR)/build

re: fclean all

.PHONY: all fclean clean re
