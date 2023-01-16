/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/16 14:08:18 by dcella-d         ###   ########.fr       */
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
	t_list	*last_b;
	int		posAB;

	posAB = check_pos(lst_b, lst_a);
	last_b = get_last(lst_b);
	if ((lst_b->pos > lst_b->next->pos) && (lst_b->pos > last_b->pos) \
	&& (posAB == 1))
		return (10);
	else if (lst_b->next->pos > lst_b->pos)
		return (6);
	else if (last_b->pos > lst_b->pos)
		return (8);
	//else if (posAB == counter)
	else if (posAB > (counter/2))
		return (7);
	else if (posAB < (counter/2))
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
		count++;
		if (lst_b < temp)
			break;
		temp = temp->next;	
	}
	return (count);
}