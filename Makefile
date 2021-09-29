SRCS = addelem.c \
		delelem.c \
		init_list.c \
		is_chislo.c \
		main.c \
		sa_sb_ss.c \
		utils.c \
		create_list.c \
		check_pa_or_pb.c \
		pa_pb.c \
		ra_rb_rr.c \
		sort_two_el.c \
		ft_strdup.c \
		sort_three_el.c \
		rra_rrb_rrr.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CFLAGS = -Werror -Wall -Wextra -g

CC = gcc

RM = rm -rf

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# $(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# main.o: main.c
# 	gcc -c main.c -o main.o


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# all: $(NAME)

# $(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)