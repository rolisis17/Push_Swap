/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:38:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/07 14:36:06 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.*/

/*	3, 4	*/

void	swap_top_bonus(t_list **lst)
{
	t_list	*last;
	t_list	*prev;
	int		temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = (*lst);
	prev = last->next;
	temp = last->content;
	last->content = prev->content;
	prev->content = temp;
	temp = last->pos;
	last->pos = prev->pos;
	prev->pos = temp;
}

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.*/

/*	5,	6	*/

void	swap_rotate_bonus(t_list **lst)
{
	t_list	*last;
	t_list	*second;
	t_list	*head;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = (*lst);
	while (last->next != NULL)
		last = last->next;
	second = (*lst)->next;
	second->prev = NULL;
	head = (*lst);
	head->next = NULL;
	head->prev = last;
	last->next = head;
	(*lst) = second;
}

/*	7,	8	*/

void	swap_reverse_bonus(t_list **lst)
{
	t_list	*last;
	t_list	*previous;
	t_list	*head;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = (*lst);
	while (last->next != NULL)
		last = last->next;
	previous = last->prev;
	head = (*lst);
	last->next = head;
	head->prev = last;
	previous->next = NULL;
	(*lst) = last;
}

/*	9,	10	*/

void	swap_ab_bonus(t_list **from, t_list **to)
{
	t_list	*lasthead;

	lasthead = (*from);
	if (!(*from) || !(*from)->next)
		return ;
	if ((*from)->next != NULL)
	{
		(*from) = (*from)->next;
		(*from)->prev = NULL;
		lasthead->next = NULL;
	}
	else
		(*from) = NULL;
	if ((*to) != NULL)
	{
		lasthead->next = (*to);
		(*to)->prev = lasthead;
	}
	else
		(*to) = lasthead;
}

void	print_ok(t_list **lst_a, t_list **lst_b)
{
	if (check_order_bonus(*lst_a) && !(*lst_b))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
