/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/12 20:06:44 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int chislo;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

t_list		*create_list(int argc, char **argv);
int			is_chislo(int argc, char **argv);
int			ft_atoi(const char *string);
// работа с списками
t_list		*init_list(char *str);
t_list		*addelem(t_list *stack, char *new_chislo);
t_list		*delelem(t_list *stack);
t_list		*delhead(t_list *root);
// инструкции
void	sa_or_sb(t_list *stack);
void	pa_or_pb(t_list *stack_a, t_list *stack_b);
#endif