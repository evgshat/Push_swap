/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/29 23:07:04 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				chislo;
	struct s_list	*prev;
	struct s_list	*next;
	int				order;
}	t_list;

t_list		*create_list(int argc, char **argv);
int			is_chislo(int argc, char **argv);
int			ft_atoi(const char *string);
char		*ft_strdup(const char *str);
// работа с списками
t_list		*init_list(char *str);
t_list		*addelem(t_list **stack, char *new_chislo);
t_list		*delelem(t_list *stack);
t_list		*delhead(t_list *root);

// инструкции
void		sa(t_list **stack, int is_ss);
void		sb(t_list **stack, int is_ss);
void		ss(t_list **stack_a, t_list **stack_b);
//
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
//
void		ra(t_list **stack, int is_rr);
void		rb(t_list **stack, int is_rr);
void		rr(t_list **stack_a, t_list **stack_b);
//
void		rra(t_list **stack, int is_rrr);
void		rrb(t_list **stack, int is_rrr);
void		rrr(t_list **stack_a, t_list **stack_b);
// check
void		check_pa_or_pb(t_list **stack_a);

//sort
void	sort_two_el(t_list	**stack);
void	sort_three_el(t_list	**stack);

#endif