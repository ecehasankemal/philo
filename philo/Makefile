NAME = philo

CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = philo.h
RM = rm -f

LIST =	main.c utils.c parser.c init.c basis.c threads.c

OBJ = $(LIST:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
