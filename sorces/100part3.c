/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100part3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:10:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/24 19:32:05 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	tacountnbrposition(t_list *lst_a, int nbr)
{
	int	counter;

	counter = 1;
	if (nbr == 0)
		return (-1);
	while (lst_a->pos != nbr)
	{
		counter++;
		lst_a = lst_a->next;
	}
	return (counter);
}

int	talowerchecker(t_list *lst_a, int pos)
{
	int	counter;

	counter = 0;
	while (lst_a)
	{
		if (pos > lst_a->pos)
			counter++;
		lst_a = lst_a->next;
	}
	return (counter);
}

int	talowerfinder(t_list *lst_a, int pos)
{
	int	nbr;

	nbr = 0;
	while (lst_a)
	{
		if (pos > lst_a->pos && lst_a->pos > nbr)
			nbr = lst_a->pos;
		lst_a = lst_a->next;
	}
	return (nbr);
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
		div += counter_a / 3;
	return (div / 2);
}
