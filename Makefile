NAME = pipex

LIST =  src/main.c src/utils.c

LIST_B = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src_bonus/main_bonus.c src_bonus/utils_bonus.c src_bonus/utils_two_bonus.c

OBJ = $(patsubst %.c, %.o, $(LIST))

OBJ_B = $(patsubst %.c, %.o, $(LIST_B))

HEAD = src/pipex.h

BONUS_BIN = ./pipex_bonus

HEAD_B = src_bonus/pipex_bonus.h

DIR = ./libft_finish

LIB = libft_finish/libft.a

FLAGS = -Wall -Wextra -Werror

all	: $(NAME)

$(NAME)	: $(OBJ) $(HEAD)
	$(MAKE) -C $(DIR)
	gcc $(FLAGS) $(LIB) $(OBJ) -o $(NAME)

%.o	: %.c
	gcc $(FLAGS) -c $< -o $@

clean	:
	$(MAKE) clean -C $(DIR)
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean	: clean
	$(MAKE) fclean -C $(DIR)
	rm -f $(NAME)

bonus	: $(BONUS_BIN)

$(BONUS_BIN): $(OBJ_B) $(HEAD_B)
	$(MAKE) -C $(DIR)
	gcc $(FLAGS) $(LIB) $(OBJ_B) -o $(BONUS_BIN)

re	 : fclean all

.PHONY	: all clean fclean re