NAME		= so_long
SRC			= so_long.c ./utils/init_map.c ./utils/errors.c ./utils/map_checks.c ./utils/map_checks_2.c
OBJ			= $(SRC:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_AR	= ./libft/libft.a
LIBFT		= ./libft

all: $(NAME)

$(LIBFT_AR):
	@make -C $(LIBFT)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_AR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_AR)

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all