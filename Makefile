NAME = philo

SRC = philo.c errors1.c checks.c parsing.c utils1.c main.c printing.c to_do.c init.c

OBJ = $(SRC:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror -pthread 

all : $(NAME)

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re : fclean all
