/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoii.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:03 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/13 19:56:26 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	lessthanthree(t_list *lst_a)
{
	int bigger;

	bigger = check_bigger(lst_a, NULL);
	if (bigger == 2)
	{
		if (get_last(lst_a)->content < (lst_a)->content)
			return (5);
		else 
			return (3);
	}
	else if (bigger != 2)
	{
		if (bigger == 1)
			return (7);
		else
			return (3);
	}
	return (0);
}

int	b3(t_list *lst_b)
{
	int	counter_b;
	int bigger;

	counter_b = count_lst(lst_b);
	bigger = check_bigger(lst_b, NULL);
	if (counter_b > 1)
	{
		if (bigger == 2)
		{
			if (get_last(lst_b)->content > (lst_b)->content)
				return (8);
			else 
				return (4);
		}
		else if (bigger != 2)
		{
			if (bigger == 1)
				return (4);
			else
				return (8);
		}
	}
	return (0);
}

int	lessthanseven(t_list *lst_a, int counter_a, int counter)
{
	t_list	*temp;
	int	pos;

	temp = lst_a;
	while (temp)
	{
		pos = temp->pos;
		temp = temp->next;
	};
	if (counter_a == 6)
	{
		if (lst_a->pos <= (counter/2))
			return (9);
		else if (lst_a->pos > (counter/2))
			return (7);
	}
	else
	{
		if (lst_a->pos <= (counter/2))
			return (9);
		else if (lst_a->next->pos <= (counter/2))
			return(3);
		else
			return (7);
	}
	return (0);
}

int	morethansix(t_list *lst_a, t_list *lst_b, int counter_a, int counter_b, int laststep)
{
	if (laststep == 1)
		return (upto100partiii(lst_a, lst_b, counter_a));
	else if (counter_a > 3)
		return (upto100partii(lst_a, counter_a));
	else if (check_pos(lst_a, counter_a + counter_b))
		return (upto100parti(lst_a, counter_a + counter_b));
	
	return (0);
}
