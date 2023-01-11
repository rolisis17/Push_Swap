/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:20:01 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/11 13:47:18 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	algo(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_a;
	int	counter_a;
	int pos;

	last_a = (*lst_a);
	while (last_a)
	{
		pos = last_a->pos;
		last_a = last_a->next;
	}
	counter_a = count_lst(*lst_a);
	// last_a = get_last(*lst_a);
	if (*lst_b && check_order(*lst_a) && check_order_b(*lst_b))
	{
		check_swap(&lst_b, &lst_a, 10);
		return ;
	}
	else if (counter_a > 3 && counter_a < 7)
		check_swap(&lst_a, &lst_b, lessthanseven(*lst_a, counter_a));
	else if (counter_a < 4)
		check_swap(&lst_a, &lst_b, lessthanthree(*lst_a));

	// if (counter_b > 1)
	// {
	// 	if ((check_bigger(last_b) == 3 && check_bigger(*lst_a) == counter_b))
	// 	check_swap(&lst_b, &lst_a, 10);
	// 	else if (counter_b <= 3 && check_bigger(last_b) != 3)
	// 	{
	// 		if (check_bigger(*lst_b) == 2)
	// 		{
	// 			if (check_bigger(last_b) == 2)
	// 				check_swap(&lst_b, &lst_a, 8);
	// 		}
	// 		else
	// 			if (check_bigger(*lst_b) < 3)
	// 				check_swap(&lst_b, &lst_a, 4);
	// 			// else if (check_bigger(*last_b) == 2)
	// 			// 	check_swap(&lst_b, &lst_a, 4);
	// 	}
	// }
}
