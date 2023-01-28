/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkswap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:21:41 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/28 13:03:40 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	do_swap(char *move, t_list **lst_a, t_list **lst_b)
{
	if (!(ft_strcmp(move, "sa\n")))
		swap_top_bonus(lst_a);
	else if (!(ft_strcmp(move, "sb\n")))
		swap_top_bonus(lst_b);
	else if (!(ft_strcmp(move, "ra\n")))
		swap_rotate_bonus(lst_a);
	else if (!(ft_strcmp(move, "rb\n")))
		swap_rotate_bonus(lst_b);
	else if (!(ft_strcmp(move, "rra\n")))
		swap_reverse_bonus(lst_a);
	else if (!(ft_strcmp(move, "rrb\n")))
		swap_reverse_bonus(lst_b);
	else if (!(ft_strcmp(move, "pb\n")))
		swap_ab_bonus(lst_a, lst_b);
	else if (!(ft_strcmp(move, "pa\n")))
		swap_ab_bonus(lst_b, lst_a);
	else
		show_mov_bonus(lst_a, lst_b, move);
}

void	show_mov_bonus(t_list **lst_a, t_list **lst_b, char *move)
{
	if (!(ft_strcmp(move, "ss\n")))
	{
		do_swap("sa\n", lst_a, lst_b);
		do_swap("sb\n", lst_a, lst_b);
	}
	else if (!(ft_strcmp(move, "rr\n")))
	{
		do_swap("ra\n", lst_a, lst_b);
		do_swap("rb\n", lst_a, lst_b);
	}
	else if (!(ft_strcmp(move, "rrr\n")))
	{
		do_swap("rra\n", lst_a, lst_b);
		do_swap("rrb\n", lst_a, lst_b);
	}
	else if (!(ft_strcmp(move, "Error\n")))
		return ;
	else
		write(1, "Error\n", 6);
	
}

int	check_order_bonus(t_list *lst)
{
	if (!lst)
		return (3);
	while ((lst)->next != NULL)
	{
		if ((lst)->content > (lst)->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*get_last_bonus(t_list *lst_a)
{
	t_list	*last_a;

	last_a = lst_a;
	while (last_a != NULL)
	{
		if (last_a->next != NULL)
			last_a = last_a->next;
		else
			break ;
	}
	return (last_a);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	f;

	f = 0;
	while (s1[f] || s2[f])
	{
		if (s1[f] != s2[f])
			return ((unsigned char)s1[f] - (unsigned char)s2[f]);
		f++;
	}
	return (0);
}
