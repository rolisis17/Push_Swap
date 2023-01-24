/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/24 19:47:11 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	upto100parti(t_list **lst_a, t_list **lst_b, int counter)
{
	static int	keep;
	static int	counter_b;

	if ((count_lst(*lst_b) >= 2 && (keep == 0)) \
	&& counter_b < count_lst(*lst_b))
	{
		keep = 1;
		counter_b = count_lst(*lst_b);
		return (upto100partib(*lst_b, counter));
	}
	else
		keep = 0;
	return (upto100partia(*lst_a, counter));
}

int	upto100partib(t_list *lst, int counter)
{
	int	div;

	div = chunkdiv(0, 2);
	if (lst->pos >= counter - div)
		return (6);
	return (0);
}

int	upto100partia(t_list *lst_a, int counter)
{
	static int	check;
	int			div;

	div = change_div(lst_a, counter);
	if (!check)
	{
		if ((get_last(lst_a)->pos <= (div)) || \
		(get_last(lst_a)->pos >= counter - (div)))
			return (7);
		else
			check = 1;
	}
	if ((lst_a->pos <= div) || (lst_a->pos >= counter - div))
		return (9);
	return (5);
}

int	upto100partiii(t_list **lst_a, t_list **lst_b, int counter_a)
{
	int	posa;

	if (lst_b > 0)
		taclosest(lst_b, taclosesposition(lst_a, lst_b, counter_a));
	if (talowerchecker(*lst_a, (*lst_b)->pos))
	{
		posa = tacountnbrposition(*lst_a, talowerfinder(*lst_a, (*lst_b)->pos));
		if (posa > 0 && posa != counter_a)
			return (choose_rotate2(posa, counter_a, 0));
		else if (posa == counter_a)
			return (10);
	}
	else
	{
		if (findlowestbeforerotate(*lst_a) != 1)
			return (choose_rotate2(findlowestbeforerotate(*lst_a), \
			counter_a, 0));
		else
			return (10);
	}
	return (0);
}

int	upto100partiv(t_list *lst_a, int counter)
{
	if (!check_order(lst_a))
		return (choose_rotate(tacountnbrposition(lst_a, 1), counter));
	return (0);
}
