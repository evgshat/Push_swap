SRCS =	./src/addelem.c \
		./src/init_list.c \
		./src/is_norm_args.c \
		./src/main.c \
		./src/sa_sb_ss.c \
		./src/create_list.c \
		./src/pa_pb.c \
		./src/ra_rb_rr.c \
		./src/sort_two_el.c \
		./src/sort_three_el.c \
		./src/rra_rrb_rrr.c \
		./src/sort_four_el.c \
		./src/sort_five_el.c \
		./src/create_massiv.c \
		./src/algoritm.c \
		./src/put_in_a.c \
		./src/back_to_b.c \
		./src/sort_second_half.c \
		./src/put_in_b.c \
		./src/utils_for_put_a_b.c \
		./src/utils_for_put_a_b_2.c \
		./src/check_double.c \
		./src/check_next_element.c

SRCS_B =	./src_bonus/main_bonus.c \
			./src_bonus/pa_pb_bonus.c \
			./src_bonus/ra_rb_rr_bonus.c \
			./src_bonus/rra_rrb_rrr_bonus.c \
			./src_bonus/sa_sb_ss_bonus.c \
			./src_bonus/create_list_bonus.c \
			./src_bonus/is_norm_args_bonus.c \
			./src_bonus/init_list_bonus.c \
			./src_bonus/addelem_bonus.c \
			./src_bonus/utils_for_put_a_b_2_bonus.c \
			./src_bonus/create_massiv_bonus.c \
			./src_bonus/check_double_bonus.c \
			./src_bonus/check_next_element_bonus.c \
			./src_bonus/utils_for_put_a_b_bonus.c \
			./src_bonus/get_next_line_bonus.c \
			./src_bonus/get_next_line_utils_bonus.c \
			./src_bonus/utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

NAME = push_swap
NAME_B = checker

CFLAGS = -Werror -Wall -Wextra -g

CC = gcc

RM = rm -rf

HEADER = push_swap.h
HEADER_B = push_swap_bonus.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B) $(NAME)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $@

%.o: %.c $(HEADER_B) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re