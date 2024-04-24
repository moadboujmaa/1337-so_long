NAME		= so_long
SRC			= so_long.c ./utils/parse_map.c ./utils/errors.c ./utils/map_checks.c ./utils/map_checks_2.c ./utils/utils.c ./utils/init_mlx.c
OBJ			= $(SRC:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= MLX42/build/libmlx42.a MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit
LIBFT_AR	= ./libft/libft.a
LIBFT		= ./libft

all: $(NAME)

$(LIBFT_AR):
	@make -C $(LIBFT)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_AR)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME) $(LIBFT_AR)
	@echo "  █████████     ███████              █████          ███████    ██████   █████   █████████ "
	@echo " ███░░░░░███  ███░░░░░███           ░░███         ███░░░░░███ ░░██████ ░░███   ███░░░░░███"
	@echo "░███    ░░░  ███     ░░███           ░███        ███     ░░███ ░███░███ ░███  ███     ░░░ "
	@echo "░░█████████ ░███      ░███           ░███       ░███      ░███ ░███░░███░███ ░███         "
	@echo " ░░░░░░░░███░███      ░███           ░███       ░███      ░███ ░███ ░░██████ ░███    █████"
	@echo " ███    ░███░░███     ███            ░███      █░░███     ███  ░███  ░░█████ ░░███  ░░███ "
	@echo "░░█████████  ░░░███████░   █████████ ███████████ ░░░███████░   █████  ░░█████ ░░█████████ "
	@echo " ░░░░░░░░░     ░░░░░░░    ░░░░░░░░░ ░░░░░░░░░░░    ░░░░░░░    ░░░░░    ░░░░░   ░░░░░░░░░  "

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all
