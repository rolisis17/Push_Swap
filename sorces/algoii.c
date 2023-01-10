/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoii.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:03 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/10 17:26:33 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	lessthanthree(t_list *lst_a)
{
	if (check_bigger(lst_a) == 2)
	{
		if (get_last(lst_a)->content < (lst_a)->content)
			return (5);
		else 
			return (3);
	}
	else if (check_bigger(lst_a) != 2)
	{
		if (check_bigger(lst_a) == 1)
			return (7);
		else
			return (3);
	}
	return (0);
}

int	lessthanseven(t_list *lst_a, int counter_a)
{
	if (check_half(lst_a) == 1)
		return (9);
	else if (check_half(lst_a) > counter_a/2)
		return (7);
	else if (check_half(lst_a) <= counter_a/2)
	{
		if	(check_half(lst_a) == 2)
			return (3);
		else
			return (5);
	}
	return (0);
}
