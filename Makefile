SRCS := utils.c \
		is_chislo.c \
		create_list.c \
		main.c \
		init_list.c \
		addelem.c \
		delelem.c \
		sa_or_sb.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap.a

CFLAGS = -Werror -Wall -Wextra -c -g

# $(CC) $(CFLAGS) $< -I ${HEADER} -o $(<:.c=.o)

CC = gcc

RM = rm -rf

HEADER = push_swap.h

%.o: %.c $(HEADER)
	$(CC) -c $< -I ${HEADER}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# all: $(NAME)

# $(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)