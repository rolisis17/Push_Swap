/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:38:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 15:52:01 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.*/

/*	3, 4	*/

void	swap_top(t_list **lst)
{
	t_list	*last;
	t_list	*prev;
	int		temp;

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

void	swap_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*second;
	t_list	*head;

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

void	swap_reverse(t_list **lst)
{
	t_list	*last;
	t_list	*previous;
	t_list	*head;

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

void	swap_ab(t_list **from, t_list **to)
{
	t_list	*lasthead;

	lasthead = (*from);
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
	(*to) = lasthead;
}

int	check_ra_rra(int keep, int swap)
{
	if (swap == 5 || swap == 6)
	{
		if (keep != swap + 2)
		{
			show_mov(keep);
			keep = swap;
		}
		else
			keep = 0;
	}
	if (swap == 7 || swap == 8)
	{
		if (keep != swap - 2)
		{
			show_mov(keep);
			keep = swap;
		}
		else
			keep = 0;
	}
	return (keep);
}
