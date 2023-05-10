CC = cc

CFLAGS =  -pthread -g -Wall -Wextra  -Werror

NAME = philo

SRC_M = heart.c \
		Utils.c \
		Utils_2.c \
		Utils_3.c \
		handling_args.c \
		initialize.c \
		actions.c \

OBJ_M = $(SRC_M:.c=.o)

all: $(NAME)

$(OBJ_M): philo.h

$(NAME) : $(OBJ_M)
	$(CC) -g $(OBJ_M) -o $(NAME)

clean :
	rm -rf $(OBJ_M)

fclean : clean
	rm -rf $(NAME)

re : fclean all
