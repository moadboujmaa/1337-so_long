NAME		= so_long
NAME_BONUS	= so_long_bonus

SRC			= ./mandatory/so_long.c ./mandatory/utils/parse_map.c ./mandatory/utils/free_and_errors.c ./mandatory/utils/map_checks.c ./mandatory/utils/map_checks_2.c ./mandatory/utils/init_mlx.c ./mandatory/utils/move_handlers.c
SRC_BONUS	= ./bonus/so_long_bonus.c ./bonus/utils/parse_map.c ./bonus/utils/free_and_errors.c ./bonus/utils/map_checks.c ./bonus/utils/map_checks_2.c ./bonus/utils/init_mlx.c ./bonus/utils/move_handlers.c ./bonus/utils/hooks/flag_hook.c ./bonus/utils/hooks/coin_hook.c ./bonus/utils/hooks/rise_hook.c ./bonus/utils/hooks/idle_hook.c ./bonus/utils/hooks/enemy_hook.c ./bonus/utils/hooks/move_enemies.c ./bonus/utils/end_game.c ./bonus/utils/start.c ./bonus/utils/end.c ./bonus/utils/load_images.c ./bonus/utils/hooks/free_textures.c ./bonus/utils/hooks/free_textures_2.c

OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_AR	= ./shared/libft/libft.a
LIBFT		= ./shared/libft

MLX_FLAGS	= ./shared/include/libmlx42.a ./shared/include/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(LIBFT_AR):
	@make -C $(LIBFT)

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

bonus: $(OBJ_BONUS) $(LIBFT_AR)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT_AR)
	@echo "  █████████     ███████              █████          ███████    ██████   █████   █████████ "
	@echo " ███░░░░░███  ███░░░░░███           ░░███         ███░░░░░███ ░░██████ ░░███   ███░░░░░███"
	@echo "░███    ░░░  ███     ░░███           ░███        ███     ░░███ ░███░███ ░███  ███     ░░░ "
	@echo "░░█████████ ░███      ░███           ░███       ░███      ░███ ░███░░███░███ ░███             ___  ____  _  ____  ______"
	@echo " ░░░░░░░░███░███      ░███           ░███       ░███      ░███ ░███ ░░██████ ░███    █████   / _ )/ __ \/ |/ / / / / __/"
	@echo " ███    ░███░░███     ███            ░███      █░░███     ███  ░███  ░░█████ ░░███  ░░███   / _  / /_/ /    / /_/ /\ \  "
	@echo "░░█████████  ░░░███████░   █████████ ███████████ ░░░███████░   █████  ░░█████ ░░█████████  /____/\____/_/|_/\____/___/  "
	@echo " ░░░░░░░░░     ░░░░░░░    ░░░░░░░░░ ░░░░░░░░░░░    ░░░░░░░    ░░░░░    ░░░░░   ░░░░░░░░░                                "

%.o: %.c ./mandatory/so_long.h ./bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all
