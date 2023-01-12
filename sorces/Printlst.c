/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:46:13 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/12 16:18:13 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int	to_printii(int keep, int swap)
{
	if (swap == 7 || swap == 8)
	{
		if ((keep == 7 || keep == 8) && swap != keep)
			return (write(1, "rrr\n", 4) - 4);
		else
			show_mov(keep);
		keep = swap;
		return (keep);
	}
	else if (swap == 9 || swap == 10)
	{
		show_mov(keep);
		keep = swap;
		return (keep);
	}
	return (0);
}

int	to_print(int keep, int swap)
{
	if (swap == 4 || swap == 3)
	{
		if ((keep == 3 || keep == 4) && swap != keep)
			return (write(1, "ss\n", 4) - 4);
		else
			show_mov(keep);
		keep = swap;
		return (keep);
	}
	else if (swap == 5 || swap == 6)
	{
		if ((keep == 5 || keep == 6) && swap != keep)
			return (write(1, "rr\n", 4) - 4);
		else
			show_mov(keep);
		keep = swap;
		return (keep);
	}
	else if (swap > 6)
		return (to_printii(keep, swap));
	return (0);
}

void	show_mov(int keep)
{
	if (keep == 0)
		return ;
	else if (keep == 3)
		write (1, "sa\n", 4);
	else if (keep == 4)
		write (1, "sb\n", 4);
	else if (keep == 5)
		write (1, "ra\n", 4);
	else if (keep == 6)
		write (1, "rb\n", 4);
	else if (keep == 7)
		write (1, "rra\n", 4);
	else if (keep == 8)
		write (1, "rrb\n", 4);
	else if (keep == 9)
		write (1, "pb\n", 4);
	else if (keep == 10)
		write (1, "pa\n", 4);
}

void	print_lst(t_list *lst_a, t_list *lst_b)
{
	int	bcont;
	int	acont;

	acont = 0;
	bcont = 0;
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
