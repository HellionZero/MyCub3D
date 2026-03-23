NAME = cub3D
LIBS_DIR = ./libs
LIBFT_DIR = $(LIBS_DIR)/libft
PRINTF_DIR = $(LIBS_DIR)/ft_printf
OBJDIR = objects
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX42_DIR = $(LIBS_DIR)/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -I$(MLX42_DIR)/include -ldl -lglfw -pthread -lm

SRC = main.c \
window.c \

CORE_DIR = core/
SRC += $(CORE_DIR)init.c \
	  $(CORE_DIR)shutdown.c \
	  $(CORE_DIR)state.c \
	  $(CORE_DIR)config.c \

DATA_DIR = data/
SRC += $(DATA_DIR)parser.c \

ENGINE_DIR = engine/
SRC += $(ENGINE_DIR)geometry.c \
		$(ENGINE_DIR)movement.c \
		$(ENGINE_DIR)raycaster.c \

INPUT_DIR = input/
SRC += $(INPUT_DIR)hooks.c \
		$(INPUT_DIR)arrows.c \
		$(INPUT_DIR)mouse.c \
		$(INPUT_DIR)keys.c \

PLAYER_DIR = player/
SRC += $(PLAYER_DIR)player.c \
		$(PLAYER_DIR)manager.c \

RENDER_DIR = render/
SRC += $(RENDER_DIR)draw.c \
		$(RENDER_DIR)render.c \
		$(RENDER_DIR)render_utils.c \
		$(RENDER_DIR)sprites.c \
		$(RENDER_DIR)textures.c \
		$(RENDER_DIR)texture_loader.c \

SCENEGRAPH_DIR = scenegraph/
SRC += $(SCENEGRAPH_DIR)scenegraph.c \
		$(SCENEGRAPH_DIR)sg_utils.c \
		$(SCENEGRAPH_DIR)sg_render.c \
		$(SCENEGRAPH_DIR)sg_update.c \

TOOLS_DIR = tools/
SRC += $(TOOLS_DIR)debug.c \
		$(TOOLS_DIR)minimap.c \

SRC:= $(addprefix src/, $(SRC))
OBJ = $(SRC:.c=.o)
OBJ = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRC))

all: $(NAME)

$(LIBFT):
	@echo "Compiling Libft..."
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "Libft compiled."

$(PRINTF):
	@echo "Compiling ft_printf..."
	@make -C $(PRINTF_DIR) > /dev/null
	@echo "ft_printf compiled."

$(MLX42):
	@echo "Compiling MLX42..."
	if [ ! -d "$(MLX42_DIR)/build" ]; then \
		if [ ! -d "$(MLX42_DIR)" ]; then \
			git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
		fi; \
		mkdir -p $(MLX42_DIR)/build; \
	fi
	@cd $(MLX42_DIR) && cmake -B build > /dev/null 2>&1 && cmake --build build -j4 > /dev/null 2>&1
	@echo "✓ MLX42 compiled."

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX42)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX42) $(MLXFLAGS) -o $(NAME) > /dev/null
	@echo "✓ $(NAME) compiled successfully."

$(OBJDIR)/%.o: src/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I./include -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX42_DIR)/include -c $< -o $@ > /dev/null

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@echo "Cleaned object files."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "Removed $(NAME) executable."

re: fclean all

.PHONY: all clean fclean re
