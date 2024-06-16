NAME		= so_long
NAME_BONUS	= so_long_bonus

SRC		= 	so_long.c 			\
			sprites.c			\
			player.c			\
			collectibles.c		\
			victory.c			\
			map_validator.c		\
			map_playability.c	\
			map.c				\
			error.c

BONUS	= 	so_long_bonus.c 			\
			sprites_bonus.c				\
			player_bonus.c				\
			collectibles_bonus.c		\
			game_end_bonus.c			\
			map_validator_bonus.c		\
			map_playability_bonus.c		\
			map_bonus.c					\
			error_bonus.c				\
			enemy_bonus.c				\
			enemy_movement_bonus.c		\
			bonus.c

SRCOBJ	= $(SRC:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)

VPATH	= mandatory/src bonus/src
CC		= cc
RM		= rm -f
IFLAGS	= -I include
CFLAGS	= -Wall -Wextra -Werror
CAFILES = lib/libft/libft.a lib/MLX42/build/libmlx42.a
GLFW	= -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
CAFLAGS = $(CAFILES) $(IFLAGS) $(GLFW)

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

$(NAME) : libmake $(SRCOBJ)
	@$(CC) $(SRCOBJ) $(CAFLAGS) -o $(NAME)

bonus : libmake $(BONUSOBJ)
	@$(CC) $(BONUSOBJ) $(CAFLAGS) -o $(NAME_BONUS)

libmake:
	@git submodule update --init --recursive --remote
	@cd lib/libft && $(MAKE)
	@if [ ! -d "lib/MLX42/build" ]; then cd lib/MLX42 && cmake -B build; fi
	@cd lib/MLX42/build && make
	@curl https://icanhazdadjoke.com/

clean: 
	@$(RM) $(SRCOBJ)
	@$(RM) $(BONUSOBJ)
	@cd lib/libft && $(MAKE) clean
	@cd lib/MLX42/build && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@cd lib/libft && $(MAKE) fclean
	@cd lib/MLX42/build && $(MAKE) clean/fast

libclean:
	@cd lib/libft && $(MAKE) clean
	@cd lib/MLX42 && rm -rf build/

re: fclean all

libre: libclean libmake

all: $(NAME)

.PHONY: all clean fclean re libmake libclean libre
