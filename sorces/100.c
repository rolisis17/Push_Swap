/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:47 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/23 21:07:06 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	upto100parti(t_list **lst_a, t_list **lst_b, int counter)
{
	static int	keep;
	static int	counter_b;

	if ((count_lst(*lst_b) >= 2 && (keep == 0)) && counter_b < count_lst(*lst_b))
	{
		keep = 1;
		counter_b = count_lst(*lst_b);
		return (upto100partib(*lst_b, counter));
	}
	else
		keep = 0;
	return(upto100partia(*lst_a, counter));
}

// int	upto100partia(t_list *lst, int counter)
// {
// 	t_list	*head;
// 	int		next;
// 	int		last;
// 	int		previous;
// 	int		pos;

// 	head = lst;
// 	pos = head->pos;
// 	next = lst->next->pos;
// 	last = get_last(lst)->pos;
// 	previous = get_last(lst)->prev->pos;
// 	if (next < pos)
// 		pos = next;
// 	if (last < pos)
// 		pos = last;
// 	if (previous < pos)
// 		pos = previous;
// 	if (pos == next)
// 		return (3);
// 	if (pos == head->pos)
// 	{
// 		if (pos <= (counter/2))
// 			return (9);
// 		else
// 			return (7);
// 	}
// 	if ((pos == last) || (pos == previous))
// 		return (7);
// 	else
// 		return (5);
// }

int	upto100partib(t_list *lst, int counter)
{
	int div;
	
	div = chunkdiv(0, 2);
	if (lst->pos >= counter - (div/2))
			return (6);
	return (0);
}

int	chunkdiv(int counter_a, int check)
{
	static int	full;
	static int	div;
	
	if (!check)
		full = counter_a;
	if (check == 0)
	{
		if (counter_a >= 100)
			div = full / 5;
		else 
			div = full / 2;
	}
	if (check == 1)
	{
		if (div + div != full / 2)
			div += full / 2;
		else
		{
			if ((div + div / 2) == div)
				div += div / 2;
			else
				div += 1;
		}
	}
	return (div/2);
	
}

int	upto100partia(t_list *lst_a, int counter)
{
	static int	check;
	int			div;

	div = change_div(lst_a, counter);
	if (!check)
	{
		if ((get_last(lst_a)->pos <= (div)) ||  (get_last(lst_a)->pos >= counter - (div)))
			return (7);
		else
			check = 1;
	}
	if ((lst_a->pos <= (div)) ||  (lst_a->pos >= counter - (div)))
		return (9);
	return (5);
}

int	change_div(t_list *lst_a, int counter)
{
	int	div;
	
	div = chunkdiv(count_lst(lst_a), 2);
	if (!div)
		div = chunkdiv(count_lst(lst_a), 0);
	while (lst_a)
	{
		if (((lst_a)->pos <= (div)) || ((lst_a)->pos >= (counter - (div))))
			return (div);
		lst_a = lst_a->next;
	}
	return (chunkdiv(count_lst(lst_a), 1));
}

// int	upto100partii(t_list *lst_a, t_list *lst_b)
// {
// 	static int	keep;

// 	if (count_lst(lst_b) > 4 && keep == 0)
// 	{
// 		keep = 1;
// 		if (count_lst(lst_b) == 3)
// 			return (b3(lst_b));
// 		return (upto100partiib(lst_b));
// 	}
// 	else
// 		keep = 0;
// 	return(upto100partiia(lst_a, count_lst(lst_a)));
// }

// int	upto100partiia(t_list *lst, int counter)
// {
// 	t_list	*last;
	
// 	last = get_last(lst);
// 	while (counter > 3)
// 	{
// 		if ((lst->pos < lst->next->pos) && (last->pos > lst->pos))
// 			return (9);
// 		else if (lst->next->pos < lst->pos)
// 			return (3);
// 		else if (last->pos > lst->pos)
// 			return (5);
// 		else
// 			return (7);
// 	}
// 	return (0);
// }

// int	upto100partiib(t_list *lst)
// {
// 	t_list	*head;
// 	static int keep;
// 	int		next;
// 	int		last;
// 	int		pos;

// 	head = lst;
// 	pos = head->pos;
// 	next = lst->next->pos;
// 	last = get_last(lst)->pos;
// 	if (next > pos)
// 		return (4);
// 	if (pos < next)
// 	{
// 		keep += 1;
// 		return (6);
// 	}
// 	if (pos < last)
// 		return (6);
// 	else
// 	{
// 		if (keep > 0)
// 		{
// 			keep -= 1;
// 			return (8);
// 		}
// 		else
// 			return (0);
// 	}
// }


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

int	upto100partiii(t_list **lst_a, t_list **lst_b, int counter_a)
{
	static t_list	*temp;
	static int	posb;
	int			posA;
	
	posA = 0;
	if (posb == 0)
	{
		temp = (*lst_b);
		if (count_lst((*lst_b)) > 3)
			temp = tacloses(lst_b, taclosesposition(lst_a, lst_b, counter_a));
		else if (count_lst(*lst_b) > 1 && (!check_order_b(*lst_b)))
			return (b3(*lst_b));
		if (temp->pos != (*lst_b)->pos)
			posb = distancetohead(tacountnbrposition((*lst_b), temp->pos), count_lst(*lst_b));
	}
	posb = rotatebchecker(lst_b, posb);
	if (talowerchecker(*lst_a, temp->pos))
	{
		posA = tacountnbrposition(*lst_a, talowerfinder(*lst_a, temp->pos));
		if (posA == counter_a && temp == (*lst_b))
			return (10);
		else if (posA > 0 && posA != counter_a)
			return (choose_rotate2(posA, counter_a, 0));
	}
	else
		if (findlowestbeforerotate(*lst_a) != 1)
			return (choose_rotate2(findlowestbeforerotate(*lst_a), counter_a, 0));
		else
			return (10);
	return (0);
}

t_list	*tacloses(t_list **lst_b, int counter)
{
	if (counter == -1)
		return (get_last(*lst_b));
	else if (counter == 1)
		return ((*lst_b)->next);
	else if (counter == 2)
		return ((*lst_b)->next->next);
	else if (counter == 3)
		return ((*lst_b)->next->next->next);
	else
		return ((*lst_b));
}

int	taclosesposition(t_list **lst_a, t_list **lst_b, int a)
{
	int	count1;
	int	count2;
	int	count3;
	int	count4;
	
	if (talowerchecker((*lst_a), (*lst_b)->pos))
		count1 = tacountnbrposition(*lst_a, talowerfinder((*lst_a),\
		(*lst_b)->pos));
	else
		count1 = findlowestbeforerotate(*lst_a);
	if (talowerchecker((*lst_a), (*lst_b)->next->pos))
		count2 = tacountnbrposition(*lst_a, talowerfinder((*lst_a),\
		(*lst_b)->next->pos)) + 1;
	else
		count2 = findlowestbeforerotate(*lst_a) + 1;
	if (talowerchecker((*lst_a), (*lst_b)->next->next->pos))
		count3 = tacountnbrposition(*lst_a, talowerfinder((*lst_a),\
		(*lst_b)->next->next->pos)) + 2;
	else
		count3 = findlowestbeforerotate(*lst_a) + 2;
	if (talowerchecker((*lst_a), get_last((*lst_b))->pos))
		count4 = tacountnbrposition(*lst_a, talowerfinder((*lst_a),\
		get_last((*lst_b))->pos)) + 1;
	else
		count4 = findlowestbeforerotate(*lst_a) + 1;
	return (tabesttomove(choose_rotate2(count1, a, 1),choose_rotate2(count2, a, 1),\
	choose_rotate2(count3, a, 1), choose_rotate2(count4, a, 1)));
}

int	tabesttomove(int count1, int count2, int count3, int count4)
{
	if (count1 >= 0 && count1 < count2 && count1 < count3 && count1 < count4)
		return (0);
	if (count2 >= 0 && count2 < count1 && count2 < count3 && count2 < count4)
		return (1);
	if (count3 >= 0 && count3 < count2 && count3 < count1 && count3 < count4)
		return (2);
	if (count4 >= 0 && count4 < count2 && count4 < count1 && count4 < count3)
		return (-1);
	else
		return (0);
}

int	tacountnbrposition(t_list *lst_a, int nbr)
{
	int	counter;

	counter = 1;
	if (nbr == 0)
		return (-1);
	while (lst_a->pos != nbr)
	{
		counter++;
		lst_a = lst_a->next;
	}
	return (counter);
}

int talowerchecker(t_list *lst_a, int pos)
{
	int	counter;

	counter = 0;
	while (lst_a)
	{
		if (pos > lst_a->pos)
			counter++;
		lst_a = lst_a->next;
	}
	return (counter);
}

int	talowerfinder(t_list *lst_a, int pos)
{
	int	nbr;

	nbr = 0;
	while (lst_a)
	{
		if (pos > lst_a->pos && lst_a->pos > nbr)
			nbr = lst_a->pos;
		lst_a = lst_a->next;
	}
	return (nbr);
}

int	upto100partiv(t_list *lst_a, int counter)
{
	if (!check_order(lst_a))
			return (choose_rotate\
			(tacountnbrposition(lst_a, 1), counter));
	return (0);
}
