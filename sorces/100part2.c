/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100part2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/24 20:51:50 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	change_div(t_list *lst_a, int counter)
{
	int	div;
	int	count_a;

	count_a = count_lst(lst_a);
	div = chunkdiv(count_a, 2);
	if (!div)
		div = chunkdiv(count_a, 0);
	while (lst_a)
	{
		if (((lst_a)->pos <= (div)) || ((lst_a)->pos >= (counter - (div))))
			return (div);
		lst_a = lst_a->next;
	}
	return (chunkdiv(count_a, 1));
}

int	rotatebchecker(t_list **lst_b, int pos)
{
	if (pos != 0)
	{
		if (pos < 0)
		{
			check_swap(lst_b, NULL, 8);
			return (pos + 1);
		}
		else
		{
			check_swap(lst_b, NULL, 6);
			return (pos - 1);
		}
	}
	return (0);
}

void	taclosest(t_list **lst_b, int counter)
{
	if (counter == -1)
		check_swap(lst_b, NULL, 8);
	else if (counter == 1)
		check_swap(lst_b, NULL, 6);
	else
		return ;
}

int	taclosesposition(t_list **lst_a, t_list **lst_b, int a)
{
	int		count1;
	int		count2;
	int		count3;
	t_list	*last;

	last = get_last((*lst_b));
	if (talowerchecker((*lst_a), (*lst_b)->pos))
		count1 = tacountnbrposition(*lst_a, talowerfinder((*lst_a), \
		(*lst_b)->pos));
	else
		count1 = findlowestbeforerotate(*lst_a);
	if ((*lst_b)->next != NULL && talowerchecker((*lst_a), (*lst_b)->next->pos))
		count2 = tacountnbrposition(*lst_a, talowerfinder((*lst_a), \
		(*lst_b)->next->pos)) + 1;
	else
		count2 = findlowestbeforerotate(*lst_a) + 1;
	if (last != (*lst_b) && talowerchecker((*lst_a), last->pos))
		count3 = tacountnbrposition(*lst_a, talowerfinder((*lst_a), \
		last->pos)) + 1;
	else
		count3 = findlowestbeforerotate(*lst_a) + 1;
	return (tabesttomove(choose_rotate2(count1, a, 1), \
	choose_rotate2(count2, a, 1), choose_rotate2(count3, a, 1)));
}

int	tabesttomove(int count1, int count2, int count3)
{
	if (count1 >= 0 && count1 <= count2 && count1 <= count3)
		return (0);
	if (count2 >= 0 && count2 < count1 && count2 < count3)
		return (1);
	if (count3 >= 0 && count3 < count2 && count3 < count1)
		return (-1);
	return (0);
}
