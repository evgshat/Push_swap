SRCS = addelem.c \
		init_list.c \
		is_norm_args.c \
		main.c \
		sa_sb_ss.c \
		create_list.c \
		pa_pb.c \
		ra_rb_rr.c \
		sort_two_el.c \
		sort_three_el.c \
		rra_rrb_rrr.c \
		sort_four_el.c \
		sort_five_el.c \
		create_massiv.c \
		algoritm.c \
		put_in_a.c \
		back_to_b.c \
		sort_second_half.c \
		put_in_b.c \
		utils_for_put_a_b.c \
		utils_for_put_a_b_2.c \
		check_double.c \
		check_next_element.c

SRCS_B =  addelem.c \
		init_list.c \
		is_norm_args.c \
		sa_sb_ss.c \
		create_list.c \
		pa_pb.c \
		ra_rb_rr.c \
		sort_two_el.c \
		sort_three_el.c \
		rra_rrb_rrr.c \
		sort_four_el.c \
		sort_five_el.c \
		create_massiv.c \
		algoritm.c \
		put_in_a.c \
		back_to_b.c \
		sort_second_half.c \
		put_in_b.c \
		utils_for_put_a_b.c \
		utils_for_put_a_b_2.c \
		check_double.c \
		check_next_element.c \
		instr_for_bonus.c \
		instr_for_bonus_2.c \
		checker.c \
		get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

NAME = push_swap

NAME_B = checker

CFLAGS = -Werror -Wall -Wextra -g

CC = gcc

RM = rm -rf

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re