/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:10:10 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 12:31:44 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_nbr(char **str)
{
	t_starter	starter;

	starter.f = 0;
	starter.u = -1;
	while (str[++starter.f])
	{
		if ((str[starter.f][starter.u + 1] == 45) \
		|| (str[starter.f][starter.u + 1] == 43))
			starter.u++;
		while (str[starter.f][++starter.u])
			if ((str[starter.f][starter.u] < 48) \
			|| (str[starter.f][starter.u] > 57))
				return (0);
		starter.u = -1;
	}
	return (1);
}

int	check_doubles(t_list *lst)
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

int	check_intmax(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	else
		return (1);
}

int	error_printer(void)
{
	return (write (2, "Error\n", 6));
}
