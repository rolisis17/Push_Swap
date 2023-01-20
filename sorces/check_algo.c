/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:12 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/19 13:51:39 by dcella-d         ###   ########.fr       */
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
	// if ()
	// 	return (l)
	while (last_a != NULL)
	{
		if (last_a->next != NULL)
			last_a = last_a->next;
		else
			break ;
	}
	return (last_a);
}

int	check_bigger(t_list *lst, t_list *temp)
{
	int	f;

	f = 1;
	if (lst != NULL)
	{
		if (!temp && (lst->next != NULL))
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

void	put_pos(t_list *lst)
{
	t_list	*temp;
	t_list	*search;
	int		count;
	
	count = 0;
	temp = lst;
	search = lst;
	while (temp)
	{
		while (search)
		{
			if (search->content < temp->content)
				count++;
			if (search->next != NULL)
				search = search->next;
			else
				break;
		}
		temp->pos = count + 1;
		temp = temp->next;
		search = lst;
		count = 0;
	}
}
