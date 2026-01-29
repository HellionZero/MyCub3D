NAME = cub3D
LIBS_DIR = ./libs
LIBFT_DIR = $(LIBS_DIR)/libft
PRINTF_DIR = $(LIBS_DIR)/ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX42_DIR = $(LIBS_DIR)/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -I$(MLX42_DIR)/include -ldl -lglfw -pthread -lm

SRC = main.c \
	  init.c \

###	  parse_args.c \
	  parse_map.c \
	  parse_map_utils.c \
	  parse_textures.c \
	  parse_colors.c \
	  utils.c \
	  free.c \
	  raycasting.c \
	  raycasting_utils.c \
	  movement.c \
	  draw.c \
	  draw_utils.c \
	  minimap.c \
	  sprites.c \
	  sprites_utils.c \
	  game_loop.c \
	  hooks.c \
	  screenshot.c 	

###

SRC:= $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "Libft compiled."

$(PRINTF):
	@make -C $(PRINTF_DIR)
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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX42) $(MLXFLAGS)
	@echo "✓ $(NAME) compiled successfully."

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX42_DIR)/include -c $< -o $@

clean:
	@rm -f $(OBJ)
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
