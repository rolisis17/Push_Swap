/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:21:19 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 13:13:49 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*move;
	int		error;
	
	error = 0;
	lst_a = NULL;
	lst_b = NULL;
	move = get_next_line(0);
	error = make_list(ac, av, &lst_a);
	while (move && !(error) && (lst_a))
	{
		do_swap(move, &lst_a, &lst_b);
		if (move)
			free(move);
		move = get_next_line(0);
	}
	if (check_order_bonus(lst_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_lst_bonus(lst_a);
	if (move)
		free (move);
	return (0);
}

int	make_list(int ac, char **av, t_list **lst_a)
{
	int		error;
	
	error = 0;
	if (ac > 1)
	{
		if (is_nbr_bonus(av) == 0)
			error = error_printer();
		if (!(extract_number_bonus(lst_a, av)))
			error = error_printer();
		put_pos_bonus(lst_a);
		if (check_doubles_bonus(*lst_a) == 0)
			error = error_printer();
	}
	return (error);
}

int	extract_number_bonus(t_list **lst, char **av)
{
	static int	f;
	static int	u;
	int			sign;
	long		res;

	sign = 1;
	res = 0;
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
		if (!(check_intmax_bonus(res)))
			return (0);
		new_node_bonus(lst, res * sign);
		u = 0;
		res = 0;
		sign = 1;
	}
	return (1);
}

void	new_node_bonus(t_list **lst, int nbr)
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
		last = get_last_bonus(*lst);
		new->prev = last;
		last->next = new;
	}
	else
		*lst = new;
}

void	free_lst_bonus(t_list *lst)
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
