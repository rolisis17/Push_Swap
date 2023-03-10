/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:14:05 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 13:57:04 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		error;

	lst_a = NULL;
	lst_b = NULL;
	error = 0;
	if (ac > 1)
	{
		if (is_nbr(av) == 0)
			error = error_printer();
		if (!(extract_number(&lst_a, av)))
			error = error_printer();
		put_pos(lst_a);
		if (check_doubles(lst_a) == 0)
			error = error_printer();
		while ((!(check_order(lst_a)) || check_order(lst_b) != 3) \
		&& (error == 0))
			algo1(&lst_a, &lst_b);
		check_swap(NULL, NULL, -1);
	}
	free_lst(lst_a);
	return (0);
}

int	extract_number(t_list **lst, char **av)
{
	static int	f;
	static int	u;
	int			sign;
	static long	res;

	sign = 1;
	while (av[++f])
	{
		while (av[f][u])
		{
			if (av[f][u] == '-')
			{
				u++;
				sign = -1;
			}
			res = res * 10 + (av[f][u++] - 48);
		}
		if (!(check_intmax(res)))
			return (0);
		new_node(lst, res * sign);
		u = 0;
		res = 0;
		sign = 1;
	}
	return (1);
}

void	new_node(t_list **lst, int nbr)
{
	t_list	*new;
	t_list	*last;

	last = NULL;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = nbr;
	new->next = NULL;
	if (*lst != NULL)
	{
		last = get_last(*lst);
		new->prev = last;
		last->next = new;
	}
	else
		*lst = new;
}

void	free_lst(t_list *lst)
{
	t_list	*to_del;

	to_del = (lst);
	while ((lst) != NULL)
	{
		(lst) = (lst)->next;
		free (to_del);
		to_del = (lst);
	}
	free (lst);
	(lst) = NULL;
}
