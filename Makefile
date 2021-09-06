SRCS := main.c\
		is_digital.c\
		create_list.c\
		utils.c


OBJS = $(SRCS:.c=.o)

NAME = push_swap.a

CFLAGS = -Werror -Wall -Wextra -c -g
CC = gcc

RM = rm -rf

HEADER = push_swap.h

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -I ${HEADER} -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re