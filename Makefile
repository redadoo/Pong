NAME = Pong

SRC = $(MAIN_SRC) $(COLLIDER_SRC) $(VECTOR2_SRC)

MAIN_SRC = pong/src/*.c

COLLIDER_SRC = collider/*.c

VECTOR2_SRC = vector2/*.c

OBJ = *.o

NONE="\033[0m"
GREEN="\033[32m"
GRAY="\033[2;37m"
CURSIVE="\033[3m"

UNAME_S := $(shell uname -s)

FLAG = -lraylib

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(OBJ) $(LINKS) -o $(NAME) $(FLAG)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm -rf $(OBJ)
	
$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc -c $(SRC) $(FLAG)

play:all
	./$(NAME)


leaks: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all