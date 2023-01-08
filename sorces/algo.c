/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:20:01 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/08 13:38:39 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	algo(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_a;
	t_list	*last_b;
	int	counter_a;
	int	counter_b;

	counter_a = 1;
	counter_b = 1;
	last_a = (*lst_a);
	last_b = (*lst_b);
	while (last_a->next != NULL)
	{
		last_a = last_a->next;
		counter_a++;
	}
	while (last_b && last_b->next != NULL)
	{
		last_b = last_b->next;
		counter_b++;
	}
	if ((*lst_a)->content > (*lst_a)->next->content)
	{
		if (last_a->content < (*lst_a)->content)
			check_swap(&lst_a, &lst_b, 5);
		else
			check_swap(&lst_a, &lst_b, 3);
	}
	else
	{
		if (check_bigger(last_a) == 3)
			check_swap(&lst_a, &lst_b, 7);
		// else if (counter_a > 3)
		// 	check_swap(&lst_a, &lst_b, 9);
		else if (check_bigger(last_a) == 4)
			check_swap(&lst_a, &lst_b, 5);
		else if (counter_a > 3 && check_bigger(last_a) < 3)
		{
			check_swap(&lst_a, &lst_b, 9);
			check_swap(&lst_a, &lst_b, 9);
			check_swap(&lst_a, &lst_b, 3);
			check_swap(&lst_b, &lst_a, 10);
			check_swap(&lst_b, &lst_a, 10);
		}
		else if (check_bigger(*lst_a) == 1)
			check_swap(&lst_a, &lst_b, 3);
	}
	if (check_order(*lst_b) != 3 && (*lst_b)->next != NULL)
	{
		if ((*lst_b)->content > (*lst_b)->next->content)
		{
			if (last_b->content < (*lst_b)->content)
				check_swap(&lst_b, &lst_a, 6);
			else
				check_swap(&lst_b, &lst_a, 4);
		}
		else
		{
			if (last_b->prev->prev == (*lst_b))
				check_swap(&lst_b, &lst_a, 8);
			else if (last_b->prev != (*lst_b) && check_order_b(*lst_b) == 1)
				check_swap(&lst_b, &lst_a, 10);
		}
	}
}


int	check_bigger(t_list *lst)
{
	t_list	*temp;
	int	f;

	f = 1;
	if (lst->next != NULL)
	{
		temp = (lst)->next;
		while (((lst)->content > temp->content) && (temp->next != NULL))
		{
			f++;
			temp = temp->next;
		}
	}
	else
	{
		temp = (lst)->prev;
		while ((lst->content < temp->content) && (temp->prev != NULL))
		{
			f++;
			temp = temp->prev;
		}
	}
	return (f);
}