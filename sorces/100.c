/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 12:32:31 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	upto100parti(t_list **lst_a, t_list **lst_b, int counter)
{
	static int	keep;
	static int	counter_b;

	if ((count_lst(*lst_b) >= 2 && (keep == 0)) \
	&& counter_b < count_lst(*lst_b))
	{
		keep = 1;
		counter_b = count_lst(*lst_b);
		return (upto100partib(*lst_b, count_lst(*lst_a)));
	}
	else
		keep = 0;
	return (upto100partia(*lst_a, counter));
}

int	taclosesposition(t_list **lst_a, t_list **lst_b, int a)
{
	int		count1;
	int		count2;
	int		count3;
	t_list	*last;

	last = get_last((*lst_b));
	if (talowerchecker((*lst_a), (*lst_b)->pos))
		count1 = tacountnbrposition(*lst_a, talowerfinder((*lst_a), \
		(*lst_b)->pos));
	else
		count1 = findlowestbeforerotate(*lst_a);
	if ((*lst_b)->next != NULL && talowerchecker((*lst_a), (*lst_b)->next->pos))
		count2 = tacountnbrposition(*lst_a, talowerfinder((*lst_a), \
		(*lst_b)->next->pos)) + 1;
	else
		count2 = findlowestbeforerotate(*lst_a) + 1;
	if (last != (*lst_b) && talowerchecker((*lst_a), last->pos))
		count3 = tacountnbrposition(*lst_a, talowerfinder((*lst_a), \
		last->pos)) + 1;
	else
		count3 = findlowestbeforerotate(*lst_a) + 1;
	return (tabesttomove(choose_rotate2(count1, a, 1), \
	choose_rotate2(count2, a, 1), choose_rotate2(count3, a, 1)));
}

int	tabesttomove(int count1, int count2, int count3)
{
	if (count1 >= 0 && count1 <= count2 && count1 <= count3)
		return (0);
	if (count2 >= 0 && count2 < count1 && count2 < count3)
		return (1);
	if (count3 >= 0 && count3 < count2 && count3 < count1)
		return (-1);
	return (0);
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
