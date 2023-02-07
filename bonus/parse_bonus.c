/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:10:10 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/07 13:15:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	is_nbr_bonus(char **str)
{
	int	f;
	int	u;

	f = 0;
	u = -1;
	while (str[++f])
	{
		if ((str[f][u + 1] == 45) \
		|| (str[f][u + 1] == 43))
			u++;
		while (str[f][++u])
			if ((str[f][u] < 48) \
			|| (str[f][u] > 57))
				return (0);
		u = -1;
	}
	return (1);
}

int	check_doubles_bonus(t_list *lst)
{
	t_list	*last;
	t_list	*prox;

	last = lst;
	while (last != NULL)
	{
		if (last->next == NULL)
			return (1);
		prox = last->next;
		while (prox != NULL)
		{
			if (last->content == prox->content)
				return (0);
			prox = prox->next;
		}
		last = last->next;
	}
	return (1);
}

int	check_intmax_bonus(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	else
		return (1);
}

void	put_pos_bonus(t_list **lst)
{
	t_list	*temp;
	t_list	*search;
	int		count;

	count = 0;
	temp = (*lst);
	search = (*lst);
	while (temp)
	{
		while (search)
		{
			if (search->content < temp->content)
				count++;
			if (search->next != NULL)
				search = search->next;
			else
				break ;
		}
		temp->pos = count + 1;
		temp = temp->next;
		search = (*lst);
		count = 0;
	}
}

int	error_printer(void)
{
	write (2, "Error\n", 6);
	exit (1);
}
