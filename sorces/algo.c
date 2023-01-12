/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:20:01 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/12 16:09:02 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	algo(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_a;
	int	counter_a;
	int	counter_b;

	counter_a = count_lst(*lst_a);
	counter_b = count_lst(*lst_b);
	last_a = get_last(*lst_a);
	if (*lst_b && check_order(*lst_a) && check_order_b(*lst_b))
	{
		check_swap(&lst_b, &lst_a, 10);
		if (!check_order(*lst_a))
			check_swap(&lst_a, &lst_b, 3);
		return ;
	}
	else if (counter_a > 3 && counter_a < 7)
		check_swap(&lst_a, &lst_b, lessthanseven(*lst_a, counter_a + counter_b));
	else if (counter_a < 4)
	{
		if	(counter_b > 1 && !(check_order_b(*lst_b)))
			check_swap(&lst_b, &lst_a, b3(*lst_b));
		check_swap(&lst_a, &lst_b, lessthanthree(*lst_a));
	}
}
