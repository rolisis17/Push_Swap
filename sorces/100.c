/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/16 20:44:55 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	upto100parti(int pos, int counter)
{
	if (pos <= (counter/2))
	{	
		// if (lst->next->pos < lst->pos)
		// 	return (3);
		// else if (get_last(lst)->pos < lst->pos)
		// 	return (7);
		// else
			return (9);
	}
	// else if (lst->next->pos <= (counter/2))
	// {
	// 	// if (lst->next->next->pos < lst->next->pos)
	// 	// 	return (5);
	// 	// else
	// 		return(3);
	// }
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
	t_list	*last_b;
	int		posAB;

	posAB = check_lowest(lst_b, lst_a);
	last_b = get_last(lst_b);
	if (!(posAB))
		return (10);
	else
	{
		if ((lst_b->pos > get_last(lst_a)->pos) && (lst_b->pos < lst_a->pos))
			return (10);
		else
			return (upto100parti(posAB, counter));
	}
}

int	upto100partiv(t_list *lst_a, int counter)
{
	while (lst_a->pos != 1)
	{
		if (lst_a->pos > counter/2)
			return (7);
		else
			return (5);
	}
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
		if (lst_a->pos < lst_b->pos)
			return (count);
		temp = temp->next;
		count++;
	}
	return (0);
}