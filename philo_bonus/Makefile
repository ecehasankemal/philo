NAME = philo_bonus

CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = philo_bonus.h
RM = rm -f

LIST =	main_bonus.c parser_bonus.c utils_bonus.c \
		init_bonus.c threads_bonus.c threads_utils_bonus.c

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
