NAME = philo
FLAGS = -Wall -Wextra -g

FILES =	all input lib philo eat sleep time

SRC = $(patsubst %, source/%.c, $(FILES))
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re valg

all: $(NAME)

%.o: %.c $(HEADER)
	gcc -c $(FLAGS) $< -o $@ -I.

$(NAME):  $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_input:
	./$(NAME)
	./$(NAME) 1 2 3 4 5
	./$(NAME) 1 2 3 4

test:
	./$(NAME) 5 800 200 200

valg:
	valgrind --leak-check=full --log-file=vallog.log ./$(NAME) 5 800 200 200 5
