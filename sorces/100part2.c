/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100part2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 20:09:48 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	change_div(t_list *lst_a, int counter)
{
	int	div;
	int	count_a;

	count_a = count_lst(lst_a);
	div = chunkdiv(count_a, 2);
	if (!div)
		div = chunkdiv(count_a, 0);
	while (lst_a)
	{
		if (((lst_a)->pos <= (div)) || ((lst_a)->pos >= (counter - (div))))
			return (div);
		lst_a = lst_a->next;
	}
	div = chunkdiv(count_a, 1);
	return (div);
}

int	chunkdiv(int counter_a, int check)
{
	static int	full;
	static int	div;

	if (!check)
		full = counter_a;
	if (check == 0)
		div = full / 3;
	if (check == 1)
		div += full / 4;
	return (div / 2);
}

int	upto100partib(t_list *lst, int counter)
{
	int	div;

	div = chunkdiv(0, 2);
	if (lst->pos >= counter / 2)
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

void	taclosest(t_list **lst_b, int counter)
{
	if (counter == -1)
		check_swap(lst_b, NULL, 8);
	else if (counter == 1)
		check_swap(lst_b, NULL, 6);
	else
		return ;
}
