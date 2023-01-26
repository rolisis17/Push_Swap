/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100part2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/26 20:05:33 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	change_div(t_list *lst_a, int counter)
{
	int	div;
	int	count_a;

	(void)counter;
	count_a = count_lst(lst_a);
	div = chunkdiv(count_a, 2);
	if (!div)
		div = chunkdiv(count_a, 0);
	while (lst_a)
	{
		if ((lst_a)->pos <= (div))
			return (div);
		lst_a = lst_a->next;
	}
	return (chunkdiv(count_a, 1));
}


int	chunkdiv(int counter_a, int check)
{
	static int	full;
	static int	div;

	if (!check)
		full = counter_a;
	if (check == 0)
	{
		if(full > 100)
			div = full / 5;
		else
			div = full / 3;
	}
	if (check == 1)
	{
		if (full > 100)
			div += counter_a / 3;
		else
			div += counter_a / 2;
	}
	return (div);
}

int	upto100partib(t_list *lst, int counter)
{
	static int	div;
	static int	olddiv;
	
	if (div < chunkdiv(counter, 2))
	{
		if (div > olddiv)
			olddiv = div;
		div = chunkdiv(counter, 2);
	}
	if (lst->pos >= olddiv + ((div - olddiv) / 2) && lst->pos <= div)
		return (6);
	if (lst->pos > div)
		div += div;
	return (0);
}

int	upto100partia(t_list *lst_a, int counter)
{
	static int	check;
	int			div;

	div = change_div(lst_a, counter);
	if (!check)
	{
		if (get_last(lst_a)->pos <= div)
			return (7);
		else
			check = 1;
	}
	if ((lst_a)->pos <= (div))
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
