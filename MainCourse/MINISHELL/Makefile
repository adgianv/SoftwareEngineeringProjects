NAME = minishell
FLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR =	./libft
LIBFT = $(LIBFT_DIR)/libft.a
BUILD_DIR = ./src/build/cd.c \
			./src/build/env.c \
			./src/build/pwd.c \
			./src/parser/parser.c\
			./src/parser/utils.c \
			./src/minishell.c \
			./src/build/export.c 
SRC = $(BUILD_DIR) ## file.c 
OBJ = $(SRC:%.c=%.o)

all: $(NAME)
$(NAME):	$(OBJ)
		gcc -c $(FLAGS) $(SRC)
		@make -C libft
		# gcc $(OBJ) ${LIBFT} -o $(NAME) -lreadline -lhistory -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include
		gcc $(OBJ) ${LIBFT} -o $(NAME) -lreadline -lhistory -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include

clean:
	  rm -f $(OBJ)
	  @make clean -C libft
	  

fclean:	clean
	   rm -f $(NAME)
	   @make fclean -C libft

re: fclean all 