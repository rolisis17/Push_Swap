/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:20:01 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/24 19:40:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	algo1(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_a;
	int		counter_a;
	int		counter_b;
	int		counter;

	counter_a = count_lst(*lst_a);
	counter_b = count_lst(*lst_b);
	counter = counter_a + counter_b;
	last_a = get_last(*lst_a);
	if (*lst_b && check_order(*lst_a) && check_order_b(*lst_b) && counter < 7)
	{
		check_swap(lst_b, lst_a, 10);
		if (!check_order(*lst_a))
			check_swap(lst_a, lst_b, 3);
		return ;
	}
	else if (counter_a < 4 && counter < 7)
	{
		if (counter_b > 1 && !(check_order_b(*lst_b)))
			check_swap(lst_b, lst_a, b3(*lst_b));
		check_swap(lst_a, lst_b, lessthanthree(*lst_a));
	}
	else
		algo2(lst_a, lst_b, counter_a, counter_b);
}

void	algo2(t_list **lst_a, t_list **lst_b, int counter_a, int counter_b)
{
	int			res;
	int			counter;
	static int	laststep;

	counter = counter_a + counter_b;
	res = 0;
	if (counter_a > 3 && counter < 7)
		check_swap(lst_a, lst_b, lessthanseven(*lst_a, counter_a, counter));
	else if (counter < 501)
	{
		if (laststep == 0 && (counter_a == 3 || check_order(*lst_a)))
		{
			while (!check_order(*lst_a))
				check_swap(lst_a, lst_b, lessthanthree(*lst_a));
			laststep = 1;
		}
		res = morethansix(lst_a, lst_b, laststep);
		if (res % 2 == 0)
			check_swap(lst_b, lst_a, res);
		else
			check_swap(lst_a, lst_b, res);
	}
}
