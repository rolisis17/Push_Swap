/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/17 20:33:13 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	upto100parti(t_list *lst, int counter)
{
	if (lst->pos <= (counter/2))
	{	
		if (lst->next->pos < lst->pos)
			return (3);
		else if (get_last(lst)->pos < lst->pos)
			return (7);
		else
			return (9);
	}
	else if (lst->next->pos <= (counter/2))
	{
		if (lst->next->next->pos < lst->next->pos)
			return (5);
		else
			return(3);
	}
	else
		return (7);
}

int	upto100partii(t_list *lst, int counter)
{
	t_list	*last;
	
	last = get_last(lst);
	while (counter > 3)
	{
		if ((lst->pos < lst->next->pos) && (last->pos > lst->pos))
			return (9);
		else if (lst->next->pos < lst->pos)
			return (3);
		else if (last->pos > lst->pos)
			return (7);
		else
			return (5);
	}
	return (0);
}

int	upto100partiii(t_list *lst_a, t_list *lst_b, int counter)
{
	int		posAB;
	int		lastposA;

	posAB = check_lowest(lst_b, lst_a);
	lastposA = check_lowest(get_last(lst_a), lst_a);
	if (!(posAB))
	{
		if (lastposA == 0)
			return (10);
		else if (lastposA <= counter/2)
			return (5);
		else
			return (7);
	}
	else
	{
		if ((lst_b->pos > get_last(lst_a)->pos) && (lst_b->pos < lst_a->pos))
			return (10);
		else
		{
			if (posAB <= counter)
				return (5);
			else
				return (7);
		}	
	}
}

int	upto100partiv(t_list *lst_a, int counter)
{
	t_list	*temp;
	int		counter2;

	counter2 = 0;
	temp = lst_a;
	while (temp->pos != 1)
	{
		counter2++;
		temp = temp->next;
	}
	if (counter2 > counter/2)
		return (7);
	else
		return (5);
	return (0);
}

int	check_pos(t_list *lst_b, t_list *lst_a)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = lst_a;
	while (temp)
	{
		if (lst_b->pos > temp->pos)
			count++;
		temp = temp->next;
	}
	temp = get_last(lst_a);
	if (count == 0)
	{
		while (temp && (lst_b->pos < temp->pos))
		{
			if (lst_b->pos > temp->pos)
				break ;
			count--;
			temp = temp->prev;
		}
	}
	return (count);
}

int	check_lowest(t_list *lst_b, t_list *lst_a)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = lst_a;
	while (temp)
	{
		count++;
		if (lst_a->pos < lst_b->pos)
			return (count);
		temp = temp->next;
	}
	return (0);
}