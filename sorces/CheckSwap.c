/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckSwap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:21:41 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/21 16:14:49 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int	check_swapii(t_list **lst_a, t_list **lst_b, int swap, int keep)
{
	if (swap == 9 || swap == 10)
	{
		swap_ab(lst_a, lst_b);
		return (to_print(keep, swap));
	}
	return (0);
}

void	check_swap(t_list **lst_a, t_list **lst_b, int swap)
{
	static int	keep;

	if (swap == 0)
		return ;
	if (swap == -1)
	{
		show_mov(keep);
		keep = 0;
	}
	else if (swap == 3 || swap == 4)
	{
		swap_top(lst_a);
		keep = to_print(keep, swap);
	}
	else if (swap == 5 || swap == 6)
	{
		swap_rotate(lst_a);
		keep = to_print(keep, swap);
	}
	else if (swap == 7 || swap == 8)
	{
		swap_reverse(lst_a);
		keep = to_print(keep, swap);
	}
	else if (swap > 8)
		keep = check_swapii(lst_a, lst_b, swap, keep);
}

int	check_order(t_list	*lst)
{
	if (!lst)
		return (3);
	while ((lst)->next != NULL)
	{
		if ((lst)->content > (lst)->next->content)
		 	return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_order_b(t_list	*lst)
{
	while ((lst)->next != NULL)
	{
		if ((lst)->content < (lst)->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_stacks(t_list *lst, int counter)
{
	while (lst)
	{
		if (lst->pos <= (counter/2))
			return (1);
		lst = lst->next;
	}
	return (0);
}
