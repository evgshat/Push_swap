/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delhead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/09/12 17:54:09 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *delhead(t_list *root)
{
	t_list *temp;

	temp = root->next;
	temp->prev = NULL;
	free(root);
	return (temp);
}
