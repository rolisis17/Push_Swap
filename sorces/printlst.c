/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:46:13 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 15:51:57 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	to_printii(int keep, int swap)
{
	if (swap == 7 || swap == 8)
	{
		if ((keep == 7 || keep == 8) && swap != keep)
			return (write(1, "rrr\n", 4) - 4);
		else
			return (check_ra_rra(keep, swap));
		keep = swap;
		return (keep);
	}
	else if (swap == 9 || swap == 10)
		return (check_pa_pb(keep, swap));
	return (0);
}

int	to_print(int keep, int swap)
{
	if (swap == 4 || swap == 3)
	{
		if ((keep == 3 || keep == 4) && swap != keep)
			return (write(1, "ss\n", 3) - 3);
		else if (keep != swap)
		{
			show_mov(keep);
			keep = swap;
		}
		else
			keep = 0;
		return (keep);
	}
	else if (swap == 5 || swap == 6)
	{
		if ((keep == 5 || keep == 6) && swap != keep)
			return (write(1, "rr\n", 3) - 3);
		else
			return (check_ra_rra(keep, swap));
	}
	else
		return (to_printii(keep, swap));
}

int	check_pa_pb(int keep, int swap)
{
	if (swap == 9)
	{
		if (keep != swap + 1)
		{
			show_mov(keep);
			keep = swap;
		}
		else
			keep = 0;
	}
	if (swap == 10)
	{
		if (keep != swap - 1)
		{
			show_mov(keep);
			keep = swap;
		}
		else
			keep = 0;
	}
	return (keep);
}

void	show_mov(int keep)
{
	if (keep == 0)
		return ;
	else if (keep == 3)
		write (1, "sa\n", 3);
	else if (keep == 4)
		write (1, "sb\n", 3);
	else if (keep == 5)
		write (1, "ra\n", 3);
	else if (keep == 6)
		write (1, "rb\n", 3);
	else if (keep == 7)
		write (1, "rra\n", 4);
	else if (keep == 8)
		write (1, "rrb\n", 4);
	else if (keep == 9)
		write (1, "pb\n", 3);
	else if (keep == 10)
		write (1, "pa\n", 3);
}

void	print_lst(t_list *lst_a, t_list *lst_b)
{
	if (check_order(lst_a))
	{
		printf("------\n");
		printf("OK\n");
	}
	else
		printf("Wrong order, cunt!\n");
	while (lst_a != NULL)
	{
		printf("stack_a: %d\n", lst_a->content);
		lst_a = lst_a->next;
	}
	printf("------\n");
	while (lst_b)
	{
		printf("stack_b: %d\n", lst_b->content);
		lst_b = lst_b->next;
	}
}
