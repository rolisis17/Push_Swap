/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:12 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/10 16:16:58 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	count_lst(t_list *lst)
{
	int	counter;

	counter = 0;
	if (lst)
	{
		while (lst != NULL)
		{
			counter++;
			lst = lst->next;
		}
	}
	return (counter);
}

t_list	*get_last(t_list *lst_a)
{
	t_list	*last_a;
	
	last_a = lst_a;
	while (last_a->next != NULL)
		last_a = last_a->next;
	return (last_a);
}

int	check_bigger(t_list *lst)
{
	t_list	*temp;
	int	f;

	f = 1;
	if (lst->next != NULL)
	{
		temp = (lst)->next;
		while (((temp != NULL) && (lst)->content > temp->content))
		{
			f++;
			temp = temp->next;
		}
	}
	return (f);
}

int	check_half(t_list *lst)
{
	int		f;
	int		res;
	t_list	*temp;

	f = 1;
	temp = lst;
	res = lst->content;
	while (temp != NULL)
	{
		if (res > temp->content)
			res = temp->content;
		temp = temp->next;
	}
	while (res != lst->content)
	{
		f++;
		lst = lst->next;
	}
	return (f);
}
