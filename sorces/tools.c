/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:54:27 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/24 19:51:04 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	choose_rotate(int pos, int counter_a)
{
	if (pos < (counter_a / 2))
		return (5);
	else
		return (7);
}

int	choose_rotate2(int pos, int counter_a, int lock)
{
	int	negative;

	negative = 0;
	if (pos > (counter_a / 2))
	{
		pos = counter_a - pos;
		negative = 1;
	}
	if (lock > 0)
		return (pos);
	if (negative == 0 && lock == 0)
		return (5);
	if (negative == 1 && lock == 0)
		return (7);
	else
		return (0);
}

int	findlowestbeforerotate(t_list *lst)
{
	t_list	*temp;
	int		counter;
	int		nbr;

	counter = 1;
	nbr = lst->pos;
	temp = lst;
	while (temp)
	{
		if (temp->pos < nbr)
			nbr = temp->pos;
		temp = temp->next;
	}
	while (lst && lst->pos != nbr)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
