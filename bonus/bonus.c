/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:21:19 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/07 14:28:41 by dcella-d         ###   ########.fr       */
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
	error = make_list(ac, av, &lst_a);
	move = get_next_line(0);
	while (move && !(error) && (lst_a))
	{
		do_swap(move, &lst_a, &lst_b);
		if (move)
			free(move);
		move = get_next_line(0);
	}
	if (lst_a && !error)
		print_ok(&lst_a, &lst_b);
	free_lst_bonus(lst_a, lst_b);
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

void	free_lst_bonus(t_list *lst_a, t_list *lst_b)
{
	t_list	*to_del;

	to_del = (lst_a);
	while ((lst_a) != NULL)
	{
		(lst_a) = (lst_a)->next;
		free (to_del);
		to_del = (lst_a);
	}
	free (lst_a);
	(lst_a) = NULL;
	if (lst_b)
		free_lst_bonus(lst_b, NULL);
}
