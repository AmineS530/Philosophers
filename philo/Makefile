CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -c

NAME = philosophers

SRC_M = heart.c \
		Utils.c \
		Utils_2.c \
		handling_args.c \


OBJ_M = $(SRC_M:.c=.o)

all: $(NAME)

$(OBJ_M): philo.h

$(NAME) : $(OBJ_M)
	$(CC) $(OBJ_M) -o $(NAME)

clean :
	rm -rf $(OBJ_M)

fclean : clean
	rm -rf $(NAME)

re : fclean all


