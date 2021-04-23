NAME = philo_one
FLAGS = -Wall -Wextra -g

FILES =	all input \
		lib \
		philo_one \
		eat sleep \
		time

SRC = $(patsubst %, source/%.c, $(FILES))
OBJ = $(SRC:.c=.o)

RED = \033[31m
GREEN = \033[32m
ORANGE = \033[93m
NO_COLOR = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

shout_assemble:
	@echo "$(GREEN)Assembling$(NO_COLOR)"

shout_clean:
	@echo "$(RED)Cleaning$(NO_COLOR)"

shout_test:
	@echo "$(ORANGE)Testing$(NO_COLOR)"

%.o: %.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@ -I.

$(NAME): shout_assemble $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean: shout_clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_input: shout_test
	./$(NAME)
	./$(NAME) 1 2 3 4 5
	./$(NAME) 1 2 3 4
