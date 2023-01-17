/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:54:27 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/17 19:29:38 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	*ft_mallox(size_t nmemb, size_t size)
{
	void	*nmembp;
	size_t	f;

	f = -1;
	nmembp = (void *) malloc(nmemb * size);
	if (!nmembp)
		return (NULL);
	while (++f < nmemb * size)
		((unsigned char *)nmembp)[f] = 0;
	return (nmembp);
}

int	pleasework(t_list **lst_a, t_list **lst_b, int counter_a)
{
	t_list	*temp;
	int		counter;
	int		nbr;

	temp = (*lst_a);
	counter = 0;
	nbr = 0;
	while (temp)
	{
		if ((*lst_b)->pos > temp->pos)
		{
			counter++;
			if (temp->pos > nbr)
				nbr = temp->pos;
		}
		temp = temp->next;
	}
	temp = (*lst_a);
	if (counter > 0)
	{
		counter = 0;
		while (temp->pos != nbr)
		{
			counter++;
			temp = temp->next;
		}
		while (get_last(*lst_a)->pos != nbr)
			check_swap(&lst_a, &lst_b, choose_rotate(nbr, counter_a));
	}
	else
		while (!check_order(*lst_a))
			check_swap(&lst_a, &lst_b, \
			choose_rotate(findlowestbeforerotate(*lst_a), counter_a));
	return (10);
}

int	choose_rotate(int nbr, int counter_a)
{
	if (nbr >= counter_a/2)
		return (7);
	else
		return (5);
}

int	findlowestbeforerotate(t_list *lst)
{
	t_list	*temp;
	int		counter;
	int		nbr;

	counter = lst->pos;
	nbr = lst->pos;
	temp = lst;
	while (temp)
	{
		if (temp->pos < nbr)
			nbr = temp->pos;
		temp = temp->next;
	}
	while (lst && lst->pos != nbr)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
